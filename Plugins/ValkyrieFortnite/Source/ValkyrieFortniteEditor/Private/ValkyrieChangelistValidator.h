// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorValidatorBase.h"
#include "ValkyrieChangelistValidator.generated.h"

UCLASS(Config=Game)
class UValkyrieChangelistValidator : public UEditorValidatorBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FString> BranchSuffixes;

};

