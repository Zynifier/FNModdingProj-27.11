// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseValidationDataRepository.h"
#include "CurveTableIterativeValidator.generated.h"

class UFortBaseValidator;

UCLASS()
class UFortCurveTableIterativeValidator : public UFortBaseValidator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditInstanceOnly, Instanced, Category="FortCurveTableIterativeValidator")
	TArray<TObjectPtr<UFortBaseValidator>> Validators;

};

