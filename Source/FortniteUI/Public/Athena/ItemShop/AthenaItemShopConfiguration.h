// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Athena/ItemShop/AthenaItemShopReloadMtxInfo.h"
#include "AthenaItemShopConfiguration.generated.h"

class UAthenaItemShopCarousel;
class UAthenaItemShopSection;
class UCatalogMessaging;
class UObject;

UCLASS(Config=Game, BlueprintType, Blueprintable)
class UAthenaItemShopConfiguration : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopConfiguration")
	FString SubscriptionOfferId;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopConfiguration")
	FString CrewBlingOfferId;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopConfiguration")
	TArray<FName> LimitedTimeStorefrontNames;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopConfiguration")
	FAthenaItemShopReloadMtxInfo ItemShopReloadMtxInfo;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopConfiguration")
	FName BattlePassSectionId;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopConfiguration")
	FName SubscriptionSectionId;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopConfiguration")
	TObjectPtr<UCatalogMessaging> TileViolatorTextTable;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopConfiguration", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TMap<FName, TSoftObjectPtr<UObject>> DynamicBackgrounds;

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopConfiguration")
	TSoftClassPtr<UAthenaItemShopSection> SectionWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopConfiguration")
	TSoftClassPtr<UAthenaItemShopCarousel> CarouselWidgetClass;

};

