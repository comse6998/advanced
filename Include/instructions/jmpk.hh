class jmpk : public Fjk
{
    public:
	jmpk(u08 j, u08 k) : Fjk(0x3C, j, k) {}

	bool execute()
	{
	    return true;
	}
	
	string mnemonic() const
	{
	    return "jmpk";
	}

	bool ops()
	{
	    process(new operations::jmpk(_j, _k));
	    return false;
	}
};
