// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "McpItemAware.h"
#include "STW/CollectionBook/FortCollectionBookTypes.h"
#include "FortCollectionBookPage.generated.h"

enum class EFortCollectionBookState : uint8;

UCLASS(MinimalAPI, BlueprintType)
class UFortCollectionBookPage : public UObject, public IMcpItemAware
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="CollectionBook")
	EFortCollectionBookState GetPageState() const;

	UFUNCTION(BlueprintPure, Category="CollectionBook")
	EFortCollectionBookState GetSectionState(FName SectionId) const;

private:
	UPROPERTY(Transient)
	FString TemplateId;

	UPROPERTY(Transient)
	FString InstanceId;

	UPROPERTY(Transient)
	FName PageRowName;

	UPROPERTY()
	EFortCollectionBookState State;

	UPROPERTY()
	TArray<FFortCollectionBookSectionState> SectionStates;

};

