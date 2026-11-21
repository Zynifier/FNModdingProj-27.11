// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseValidationDataRepository.h"
#include "DataTableIterativeValidator.generated.h"

class UFortBaseValidator;

UCLASS()
class UFortDataTableIterativeValidator : public UFortBaseValidator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditInstanceOnly, Instanced, Category="FortDataTableIterativeValidator")
	TArray<TObjectPtr<UFortBaseValidator>> Validators;

};

