// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseValidationDataRepository.h"
#include "IterativeValidator.generated.h"

class UFortBaseValidator;

UCLASS()
class UFortIterativeValidator : public UFortBaseValidator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortIterativeValidator")
	FName PropertyName;

	UPROPERTY(EditInstanceOnly, Instanced, Category="FortIterativeValidator")
	TArray<TObjectPtr<UFortBaseValidator>> Validators;

	UPROPERTY(EditDefaultsOnly, Category="FortIterativeValidator")
	bool bIterateOnMapValue;

};

