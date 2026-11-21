// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ChallengeBundles/Components/FortChallengeBundleItemDefinitionComponent.h"
#include "FortChallengeBundleItemDefinitionComponent_CustomMapWidget.generated.h"

class UUserWidget;

UCLASS(Abstract, BlueprintType)
class FORTNITEGAME_API UFortChallengeBundleItemDefinitionComponent_CustomMapWidget : public UFortChallengeBundleItemDefinitionComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeBundleItemDefinitionComponent_CustomMapWidget")
	TMap<FName, TSoftClassPtr<UUserWidget>> WidgetComponents;

};

