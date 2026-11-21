// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseValidationDataRepository.h"
#include "LogicalORValidator.generated.h"

class UFortBaseValidator;

UCLASS()
class UFortLogicalORValidator : public UFortBaseValidator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditInstanceOnly, Instanced, Category="FortLogicalORValidator")
	TArray<TObjectPtr<UFortBaseValidator>> Validators;

};

