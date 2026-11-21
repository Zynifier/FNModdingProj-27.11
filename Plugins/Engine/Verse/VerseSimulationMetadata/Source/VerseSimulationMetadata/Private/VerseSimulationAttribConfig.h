// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "VerseSimulationAttribConfig.generated.h"

UCLASS(Config=Engine)
class UVerseSimulationAttribConfig : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FName> AllowedEditablePropertyNames;

	UPROPERTY(Config)
	TArray<FName> DisallowedEditablePropertyNames;

	UPROPERTY(Config)
	TArray<FSoftClassPath> DisallowedObjectPropertyClasses;

	UPROPERTY(Config)
	bool bAllowTuples;

	UPROPERTY(Config)
	bool bAllowMultidimensionalArrays;

	UPROPERTY(Config)
	bool bFilterProperties;

	UPROPERTY(Config)
	bool bFilterObjectProperties;

};

