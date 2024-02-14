class jmp : public FjK
{
    private:
	string	_label;

    public:
	jmp(string L) : FjK(0x30, 0, 0) { _label = L; }

	bool execute()
	{
	    return true;
	}

	string mnemonic() const
	{
	    return "jmp";
	}

	string dasm() const
	{
	    return mnemonic() + "(" + to_string(_K) + ")";
	}

	bool ops()
	{
	    process(new operations::jmp());
	    return false;
	}
};
