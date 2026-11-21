// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CollectionNPCSharedServiceData.h"
#include "CollectionNPCServiceWidget.generated.h"

class UFortResourceItemDefinition;

USTRUCT(BlueprintType)
struct FNPCServiceWidgetData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="NPCServiceWidgetData")
	FNPCServiceData ServiceData;

	UPROPERTY(BlueprintReadOnly, Category="NPCServiceWidgetData")
	TObjectPtr<UFortResourceItemDefinition> CostResource;

	UPROPERTY(BlueprintReadOnly, Category="NPCServiceWidgetData")
	int32 CostAmountMin;

	UPROPERTY(BlueprintReadOnly, Category="NPCServiceWidgetData")
	int32 CostAmountMax;

	UPROPERTY(BlueprintReadOnly, Category="NPCServiceWidgetData")
	bool bIsLocked;

	UPROPERTY(BlueprintReadOnly, Category="NPCServiceWidgetData")
	int32 MinRequiredBenefitLevel;

	UPROPERTY()
	int32 Priority;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCollectionNPCServiceWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UCollectionNPCServiceWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void PopulateData(const FNPCServiceWidgetData& WidgetData, const bool bShowLine);

	UFUNCTION(BlueprintImplementableEvent)
	void PopulateEmpty();

};

