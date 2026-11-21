// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortCustomizationsPreloader.generated.h"

class UCustomCharacterPart;
class UFortAIPawnCustomizationDefinition;

USTRUCT()
struct FAICharacterPartsPreloadData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Priority;

	UPROPERTY()
	TObjectPtr<UCustomCharacterPart> CharacterPart;

};

USTRUCT()
struct FAIPawnCustomizationPreloadData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Priority;

	UPROPERTY()
	TObjectPtr<UFortAIPawnCustomizationDefinition> Customization;

};

UCLASS()
class UFortCustomizationsPreloader : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TSet<TObjectPtr<UCustomCharacterPart>> PrioritizedCharacterPartsNPCBudget;

	UPROPERTY(Transient)
	TSet<TObjectPtr<UCustomCharacterPart>> PrioritizedCharacterPartsPlayerBudget;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortAIPawnCustomizationDefinition>> PrioritizedAIPawnCustomizations;

};

