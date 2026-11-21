// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPath.h"
#include "Validation/FortEditorValidator.h"
#include "FortValidator_ReferenceRestriction.generated.h"

UCLASS(Abstract)
class UFortValidator_ReferenceRestriction : public UFortEditorValidator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortValidator_ReferenceRestriction")
	TArray<FSoftObjectPath> Source;

	UPROPERTY(EditDefaultsOnly, Category="FortValidator_ReferenceRestriction")
	TArray<FSoftObjectPath> CanNotReference;

};

