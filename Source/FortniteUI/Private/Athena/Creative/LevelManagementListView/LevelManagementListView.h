// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonListView.h"
#include "FortLevelSaveComponent.h"
#include "LevelManagementListView.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelEntryDeleteClicked, const FLevelInstanceListElement&, LevelInstanceListElement);

UCLASS(BlueprintType)
class ULevelManagementListView : public UCommonListView
{
	GENERATED_BODY()

public:
	ULevelManagementListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void HandleLevelEntryDeleteClicked(const FLevelInstanceListElement& LevelInstanceListElement);

	UPROPERTY()
	FOnLevelEntryDeleteClicked OnLevelEntryDeleteClicked;

};

