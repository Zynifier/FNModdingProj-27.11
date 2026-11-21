// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Layout/Margin.h"
#include "SeasonRewardsGridWidget.generated.h"

class UFortItem;
class UUserWidget;
class UWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FItemWidgetCreated, UWidget*, Widget, UFortItem*, Item);

UCLASS(meta=(Category="Fortnite UI"))
class USeasonRewardsGridWidget : public UWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="SeasonRewardsGridWidget")
	void Populate();

	UPROPERTY(EditAnywhere, Category="SeasonRewardsGridWidget")
	TSubclassOf<UUserWidget> ItemWidgetToCreate;

	UPROPERTY(BlueprintAssignable, Category="SeasonRewardsGridWidget")
	FItemWidgetCreated OnItemWidgetCreated;

	UPROPERTY(EditAnywhere, Category="SeasonRewardsGridWidget")
	FMargin ItemPadding;

	UPROPERTY(EditAnywhere, Category="SeasonRewardsGridWidget")
	FMargin ColumnPadding;

	UPROPERTY(EditAnywhere, Category="SeasonRewardsGridWidget")
	float ScrollSpeed;

};

