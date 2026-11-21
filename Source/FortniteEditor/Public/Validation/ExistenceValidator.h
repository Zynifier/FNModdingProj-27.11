// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseValidationDataRepository.h"
#include "ExistenceValidator.generated.h"

UCLASS()
class UFortExistenceValidator : public UFortBaseValidator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortExistenceValidator", meta=(EditCondition="!bValidateContainer"))
	FName PropertyName;

	UPROPERTY(EditDefaultsOnly, Category="FortExistenceValidator", meta=(EditCondition="bUseTableRowNamePropertyName"))
	FName TableRowNamePropertyName;

	UPROPERTY(EditDefaultsOnly, Category="FortExistenceValidator")
	bool bValidateContainer;

	UPROPERTY(EditDefaultsOnly, Category="FortExistenceValidator", meta=(EditCondition="!bValidateContainer"))
	bool bUseTableRowNamePropertyName;

	UPROPERTY(EditDefaultsOnly, Category="FortExistenceValidator")
	bool bSkipIfNull;

};

