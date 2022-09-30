TS=yarn tree-sitter

# This is an opinionated list of significant reason repos on GitHub
# that are representative and trick-heavy enough to be a subject
# for acceptance testing. The general idea: if `tree-sitter-reason`
# is 100% legit for this codebase, it should satisfy everyone.
wild_github_repos := reason-lang/reason-react \
										 reason-association/reason-lang.org \
										 tinymce/reason-webapi \
										 cca-io/reason-material-ui

wild_sandboxes := $(patsubst %,test_wild/%,$(wild_github_repos))

.PHONY: generate
generate: binding.gyp
	$(TS) generate

binding.gyp: binding.gyp.json
	cp $< $@

.PHONY: test
test: generate
	$(TS) test

test-focus: generate
	$(TS) test --filter focus

test_wild/%:
	@mkdir -p test_wild/
	git clone --depth=1 https://github.com/$* ./$@

.PHONY: test_wild
test_wild: $(wild_sandboxes)
	$(TS) parse --quiet --stat '$@/**/*.res*'
