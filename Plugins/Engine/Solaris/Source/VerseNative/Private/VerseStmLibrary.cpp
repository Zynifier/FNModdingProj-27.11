// Copyright Epic Games, Inc. All Rights Reserved.

#include "VerseStmLibrary.h"

#ifndef FORTSTUB_SKIP_THUNK_PARAMS
#define FORTSTUB_SKIP_THUNK_PARAMS
static void FortStub_SkipThunkParams(FFrame& Stack, UFunction* Function)
{
	if (Function)
	{
		for (TFieldIterator<FProperty> It(Function); It && It->HasAnyPropertyFlags(CPF_Parm); ++It)
		{
			if (It->HasAnyPropertyFlags(CPF_ReturnParm))
			{
				continue;
			}
			void* Temp = FMemory::Malloc(It->GetSize(), It->GetMinAlignment());
			It->InitializeValue(Temp);
			Stack.StepCompiledIn(Temp, It->GetClass());
			It->DestroyValue(Temp);
			FMemory::Free(Temp);
		}
	}
	P_FINISH;
}
#endif

DEFINE_FUNCTION(UVerseStmLibrary::execStmBegin)
{
	FortStub_SkipThunkParams(Stack, UVerseStmLibrary::StaticClass()->FindFunctionByName(TEXT("StmBegin")));
}
void UVerseStmLibrary::StmBegin()
{
}

DEFINE_FUNCTION(UVerseStmLibrary::execStmCommit)
{
	FortStub_SkipThunkParams(Stack, UVerseStmLibrary::StaticClass()->FindFunctionByName(TEXT("StmCommit")));
}
void UVerseStmLibrary::StmCommit()
{
}

DEFINE_FUNCTION(UVerseStmLibrary::execStmEnabled)
{
	FortStub_SkipThunkParams(Stack, UVerseStmLibrary::StaticClass()->FindFunctionByName(TEXT("StmEnabled")));
}
void UVerseStmLibrary::StmEnabled()
{
}

DEFINE_FUNCTION(UVerseStmLibrary::execStmEnterFrame)
{
	FortStub_SkipThunkParams(Stack, UVerseStmLibrary::StaticClass()->FindFunctionByName(TEXT("StmEnterFrame")));
}
void UVerseStmLibrary::StmEnterFrame()
{
}

DEFINE_FUNCTION(UVerseStmLibrary::execStmLeaveFrame)
{
	FortStub_SkipThunkParams(Stack, UVerseStmLibrary::StaticClass()->FindFunctionByName(TEXT("StmLeaveFrame")));
}
void UVerseStmLibrary::StmLeaveFrame()
{
}

DEFINE_FUNCTION(UVerseStmLibrary::execStmRollback)
{
	FortStub_SkipThunkParams(Stack, UVerseStmLibrary::StaticClass()->FindFunctionByName(TEXT("StmRollback")));
}
void UVerseStmLibrary::StmRollback()
{
}

DEFINE_FUNCTION(UVerseStmLibrary::execStmSave)
{
	FortStub_SkipThunkParams(Stack, UVerseStmLibrary::StaticClass()->FindFunctionByName(TEXT("StmSave")));
}
void UVerseStmLibrary::StmSave(const FakeType& Property)
{
}
