// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VerseStmLibrary.generated.h"

// Thise type is used as a stand-in for unknown element types in the below CustomThunk signatures.
// The signatures of these generic CustomThunk functions aren't used in the compiled code, and are
// only written here for the benefit of the reader.

USTRUCT()
struct FakeType
{
	GENERATED_BODY()

};

UCLASS()
class VERSENATIVE_API UVerseStmLibrary : public UObject
{
	GENERATED_BODY()

public:
	/*void*/
	UFUNCTION(CustomThunk)
	static void StmBegin();
	DECLARE_FUNCTION(execStmBegin);

	/*void*/
	UFUNCTION(CustomThunk)
	static void StmCommit();
	DECLARE_FUNCTION(execStmCommit);

	/*void*/
	UFUNCTION(CustomThunk)
	static void StmEnabled();
	DECLARE_FUNCTION(execStmEnabled);

	/*void*/
	UFUNCTION(CustomThunk)
	static void StmEnterFrame();
	DECLARE_FUNCTION(execStmEnterFrame);

	/*void*/
	UFUNCTION(CustomThunk)
	static void StmLeaveFrame();
	DECLARE_FUNCTION(execStmLeaveFrame);

	/*void*/
	UFUNCTION(CustomThunk)
	static void StmRollback();
	DECLARE_FUNCTION(execStmRollback);

	/*FReferenceProperty*/
	UFUNCTION(CustomThunk)
	static void StmSave(const FakeType& Property);
	DECLARE_FUNCTION(execStmSave);

};

