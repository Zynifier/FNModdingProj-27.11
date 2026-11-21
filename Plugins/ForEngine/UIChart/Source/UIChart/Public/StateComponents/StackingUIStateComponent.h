// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIStateComponent.h"
#include "StackingUIStateComponent.generated.h"

class UObject;
class UStackingUIStateComponent;

USTRUCT()
struct UICHART_API FUIStateComponentInstanceStack
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<UStackingUIStateComponent*> InstanceStack;

};

UCLASS(Abstract)
class UICHART_API UStackingUIStateComponent : public UUIStateComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	EStateChartResourceScope StackScope;

	UPROPERTY()
	bool bAlwaysRemoveStackingBehavior;

private:
	UPROPERTY()
	bool bIsOnStack;

};

UCLASS()
class UICHART_API UStackingUIStateComponentSharedData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TMap<UClass*, FUIStateComponentInstanceStack> InstanceStacks;

};

