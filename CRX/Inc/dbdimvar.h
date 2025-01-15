#ifndef DBDIMVAR_H
#define DBDIMVAR_H
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

// DESCRIPTION: 
// The api for dimensioning variables shared by 
//  CrxDbDatabase, 
//  CRxDbDimstyleTableRecord, and 
//  CRxDbDimension
    
    //  -------------------------  Dimension Style get methods
    //
    virtual int              dimadec  () const;  // new to R15
    virtual bool             dimalt   () const;
    virtual int              dimaltd  () const;
    //virtual double           dimaltf  () const;
    virtual double           dimaltrnd() const;  // new to R15
    virtual int              dimalttd () const;
    virtual int              dimalttz () const;
    virtual int              dimaltu  () const;
    virtual int              dimaltz  () const;
    //virtual const CxCHAR *    dimapost () const;
    virtual int              dimarcsym() const;  // new to 2007
    virtual double           dimasz   () const;
    virtual int              dimatfit () const;  // new to R15
    virtual int              dimaunit () const;
    //virtual int              dimazin  () const;  // new to R15
    //virtual CrxDbObjectId     dimblk   () const;
    //virtual CrxDbObjectId     dimblk1  () const;
    //virtual CrxDbObjectId     dimblk2  () const;
    //virtual double           dimcen   () const;
    virtual CRxCmColor        dimclrd  () const;
    virtual CRxCmColor        dimclre  () const;
    virtual CRxCmColor        dimclrt  () const;
    virtual int              dimdec   () const;
    virtual double           dimdle   () const;
    //virtual double           dimdli   () const;
    virtual CxCHAR            dimdsep  () const;  // new to R15
    virtual double           dimexe   () const;
    virtual double           dimexo   () const;
    //virtual int              dimfrac  () const;  // new to R15
    virtual double           dimgap   () const;
    //virtual double           dimjogang() const;  // new to 2007
    virtual int              dimjust  () const;
    //virtual CrxDbObjectId     dimldrblk() const;  // new to R15
    virtual double           dimlfac  () const;
    //virtual bool             dimlim   () const;
    //virtual CrxDbObjectId     dimltex1 () const;  // new to 2007
    //virtual CrxDbObjectId     dimltex2 () const;  // new to 2007
    //virtual CrxDbObjectId     dimltype () const;  // new to 2007
    virtual int              dimlunit () const;  // new to R15
    //virtual CRxDb::LineWeight dimlwd   () const;  // new to R15
    //virtual CRxDb::LineWeight dimlwe   () const;  // new to R15
    //virtual const CxCHAR *    dimpost  () const;
    virtual double           dimrnd   () const;
    //virtual bool             dimsah   () const;
    virtual double           dimscale () const;
    virtual bool             dimsd1   () const;
    virtual bool             dimsd2   () const;
    virtual bool             dimse1   () const;
    virtual bool             dimse2   () const;
    //virtual bool             dimsoxd  () const;
    virtual int              dimtad   () const;
    virtual int              dimtdec  () const;
    virtual double           dimtfac  () const;
    //virtual int              dimtfill () const;   // new to 2007
    //virtual CrxCmColor        dimtfillclr() const; // new to 2007
    virtual bool             dimtih   () const;
    //virtual bool             dimtix   () const;
    //virtual double           dimtm    () const;
    virtual int              dimtmove () const;  // new to R15
    virtual bool             dimtofl  () const;
    //virtual bool             dimtoh   () const;
    //virtual bool             dimtol   () const;
    virtual int              dimtolj  () const;
    //virtual double           dimtp    () const;
    //virtual double           dimtsz   () const;
    //virtual double           dimtvp   () const;
    virtual CRxDbObjectId     dimtxsty () const;
    virtual double           dimtxt   () const;
    virtual int              dimtzin  () const;
    //virtual bool             dimupt   () const;
    virtual int              dimzin   () const;

    //virtual bool             dimfxlenOn  () const;  // new to R2007
    //virtual double           dimfxlen    () const;  // new to R2007

    //  -------------------------  Dimension Style set methods
    //
    virtual CDraft::ErrorStatus setDimadec  (int              v);  // new to R15
    //virtual CDraft::ErrorStatus setDimalt   (bool             v);
    virtual CDraft::ErrorStatus setDimaltd  (int              v);
    //virtual CDraft::ErrorStatus setDimaltf  (double           v);
    virtual CDraft::ErrorStatus setDimaltrnd(double           v);  // new to R15
    virtual CDraft::ErrorStatus setDimalttd (int              v);
    virtual CDraft::ErrorStatus setDimalttz (int              v);
    virtual CDraft::ErrorStatus setDimaltu  (int              v);
    virtual CDraft::ErrorStatus setDimaltz  (int              v);
    //virtual CDraft::ErrorStatus setDimapost (const CxCHAR *    v);
    virtual CDraft::ErrorStatus setDimarcsym(int              v);  // new to 2007
    virtual CDraft::ErrorStatus setDimasz   (double           v);
    virtual CDraft::ErrorStatus setDimatfit (int              v);  // new to R15
    virtual CDraft::ErrorStatus setDimaunit (int              v);
    //virtual CDraft::ErrorStatus setDimazin  (int              v);  // new to R15
    //virtual CDraft::ErrorStatus setDimblk   (CrxDbObjectId     v);  // new to R15
    //virtual CDraft::ErrorStatus setDimblk1  (CrxDbObjectId     v);  // new to R15
    //virtual CDraft::ErrorStatus setDimblk2  (CrxDbObjectId     v);  // new to R15
    //virtual CDraft::ErrorStatus setDimcen   (double           v);
    virtual CDraft::ErrorStatus setDimclrd  (const CRxCmColor& v);
    virtual CDraft::ErrorStatus setDimclre  (const CRxCmColor& v);
    virtual CDraft::ErrorStatus setDimclrt  (const CRxCmColor& v);
    virtual CDraft::ErrorStatus setDimdec   (int              v);
    virtual CDraft::ErrorStatus setDimdle   (double           v);
    //virtual CDraft::ErrorStatus setDimdli   (double           v);
    virtual CDraft::ErrorStatus setDimdsep  (CxCHAR            v);  // new to R15
    virtual CDraft::ErrorStatus setDimexe   (double           v);
    virtual CDraft::ErrorStatus setDimexo   (double           v);
    //virtual CDraft::ErrorStatus setDimfrac  (int              v);  // new to R15
    virtual CDraft::ErrorStatus setDimgap   (double           v);
    //virtual CDraft::ErrorStatus setDimjogang(double           v);  // new to 2007
    virtual CDraft::ErrorStatus setDimjust  (int              v);
   // virtual CDraft::ErrorStatus setDimldrblk(CrxDbObjectId     v);  // new to R15
    virtual CDraft::ErrorStatus setDimlfac  (double           v);
  //  virtual CDraft::ErrorStatus setDimlim   (bool             v);
   // virtual CDraft::ErrorStatus setDimltex1 (CrxDbObjectId     v);  // new to 2007
  //  virtual CDraft::ErrorStatus setDimltex2 (CrxDbObjectId     v);  // new to 2007
   // virtual CDraft::ErrorStatus setDimltype (CrxDbObjectId     v);  // new to 2007
    virtual CDraft::ErrorStatus setDimlunit (int              v);  // new to R15
   // virtual CDraft::ErrorStatus setDimlwd   (CRxDb::LineWeight v);  // new to R15
    //virtual CDraft::ErrorStatus setDimlwe   (CRxDb::LineWeight v);  // new to R15
  //  virtual CDraft::ErrorStatus setDimpost  (const CxCHAR *    v);
    virtual CDraft::ErrorStatus setDimrnd   (double           v);
  //  virtual CDraft::ErrorStatus setDimsah   (bool             v);
    virtual CDraft::ErrorStatus setDimscale (double           v);
    virtual CDraft::ErrorStatus setDimsd1   (bool             v);
    virtual CDraft::ErrorStatus setDimsd2   (bool             v);
    virtual CDraft::ErrorStatus setDimse1   (bool             v);
    virtual CDraft::ErrorStatus setDimse2   (bool             v);
   // virtual CDraft::ErrorStatus setDimsoxd  (bool             v);
    virtual CDraft::ErrorStatus setDimtad   (int              v);
    virtual CDraft::ErrorStatus setDimtdec  (int              v);
    virtual CDraft::ErrorStatus setDimtfac  (double           v);
    //virtual CDraft::ErrorStatus setDimtfill (int              v);   // new to 2007
    //virtual CDraft::ErrorStatus setDimtfillclr(const CrxCmColor& v); // new to 2007
    virtual CDraft::ErrorStatus setDimtih   (bool             v);
   // virtual CDraft::ErrorStatus setDimtix   (bool             v);
   // virtual CDraft::ErrorStatus setDimtm    (double           v);
    virtual CDraft::ErrorStatus setDimtmove (int              v);  // new to R15
    virtual CDraft::ErrorStatus setDimtofl  (bool             v);
   // virtual CDraft::ErrorStatus setDimtoh   (bool             v);
    //virtual CDraft::ErrorStatus setDimtol   (bool             v);
    virtual CDraft::ErrorStatus setDimtolj  (int              v);
    //virtual CDraft::ErrorStatus setDimtp    (double           v);
    //virtual CDraft::ErrorStatus setDimtsz   (double           v);
    //virtual CDraft::ErrorStatus setDimtvp   (double           v);
    virtual CDraft::ErrorStatus setDimtxsty (CRxDbObjectId     v);
    virtual CDraft::ErrorStatus setDimtxt   (double           v);
    virtual CDraft::ErrorStatus setDimtzin  (int              v);
    //virtual CDraft::ErrorStatus setDimupt   (bool             v);
    virtual CDraft::ErrorStatus setDimzin   (int              v);

 //   virtual CDraft::ErrorStatus setDimblk   (const CxCHAR *    v);
//    virtual CDraft::ErrorStatus setDimblk1  (const CxCHAR *    v);
 //   virtual CDraft::ErrorStatus setDimblk2  (const CxCHAR *    v);
 //   virtual CDraft::ErrorStatus setDimldrblk(const CxCHAR *    v);  // new to R15

//    virtual CDraft::ErrorStatus setDimfxlenOn (bool           v);  // new to R2007
 //   virtual CDraft::ErrorStatus setDimfxlen (double           v);  // new to R2007

#endif      // ifndef DBDIMVAR_H

