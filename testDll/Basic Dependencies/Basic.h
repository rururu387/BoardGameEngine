class Basic
{
public:
	int variable;
	Basic(int _variable);
	virtual std::string print() = 0;
};

Basic::Basic(int _variable)
{
	variable = _variable;
}