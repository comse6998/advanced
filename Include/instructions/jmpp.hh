class jmpp : public FjK
{
    private:
	string	_label;

    public:
	jmpp(u08 j, string L) : FjK(0x34, j, 0) { _label = L; }

	bool execute()
	{
	    if (0 < PROC[me()].X(_j).i()) return true;
            else return false;
	}

	string mnemonic() const
	{
	    return "jmpp";
	}

	bool ops()
	{
	    process(new operations::cmpz(_j));
	    process(new operations::jmpp());
	    return false;
	}

	void fixit()
	{
	    assert(PROC[me()].label2line.count(_label));
	    u32 targetline = PROC[me()].label2line[_label];
	    assert(PROC[me()].line2addr.count(targetline));
	    u32 targetaddr = PROC[me()].line2addr[targetline];
	    assert(PROC[me()].line2addr.count(_line));
	    u32 sourceaddr = PROC[me()].line2addr[_line];
	    _K = ((targetaddr/8) - (sourceaddr/8)) & 0xfffff;
	}
};
