// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CreativeContentBrowserTabInitializer.generated.h"

class UCreativeContentBrowserTab_CreationCondition;
class UFortCreativeContentBrowserTabPanelBase;

USTRUCT(BlueprintType)
struct FORTNITEUI_API FCreativeContentBrowserTabInitializer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CreativeContentBrowserTabInitializer")
	FText TabLabel;

	UPROPERTY(EditAnywhere, Category="CreativeContentBrowserTabInitializer")
	TSoftClassPtr<UFortCreativeContentBrowserTabPanelBase> CreativeContentBrowserTabClass;

	UPROPERTY(EditAnywhere, Instanced, Category="CreativeContentBrowserTabInitializer")
	TObjectPtr<UCreativeContentBrowserTab_CreationCondition> CreationCondition;

};

