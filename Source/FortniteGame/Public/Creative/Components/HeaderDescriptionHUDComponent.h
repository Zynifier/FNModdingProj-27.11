// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "Math/MathFwd.h"
#include "Creative/FortCreativeLoadedLinkData.h"
#include "HeaderDescriptionHUDComponent.generated.h"

class AFortPawn;
class UFortControllerComponent_Portal;
class UFortPortalComponent;
class UUserWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHUDShow, const bool, bShowPopup, const bool, bShouldAnimate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWidgetUpdate);

USTRUCT(BlueprintType)
struct FMatchmakingPortalPopupData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MatchmakingPortalPopupData")
	FText CreatorName;

	UPROPERTY(BlueprintReadWrite, Category="MatchmakingPortalPopupData")
	FText IslandName;

	UPROPERTY(BlueprintReadWrite, Category="MatchmakingPortalPopupData")
	FText IslandLinkCode;

	UPROPERTY(BlueprintReadWrite, Category="MatchmakingPortalPopupData")
	FVector WorldLocation;

};

USTRUCT(BlueprintType)
struct FPortalMatchmakingData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="PortalMatchmakingData")
	AFortPawn* LastInteractionPawn;

	UPROPERTY(BlueprintReadWrite, Export, Category="PortalMatchmakingData", meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_Portal> ControllerComponent_Portal;

	UPROPERTY(BlueprintReadWrite, Export, Category="PortalMatchmakingData", meta=(EditInline="true"))
	TObjectPtr<UFortPortalComponent> PortalComponent;

	UPROPERTY(BlueprintReadWrite, Category="PortalMatchmakingData")
	FCreativeLoadedLinkData IslandLinkData;

	UPROPERTY(BlueprintReadWrite, Category="PortalMatchmakingData")
	bool bIsPrivateMatch;

};

UCLASS(MinimalAPI, HideCategories=("Object", "Activation", "Components|Activation", "Sockets", "Base", "Lighting", "LOD", "Mesh", "Mobility", "Trigger"))
class UHeaderDescriptionHUDComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DisableTick();

	UFUNCTION(BlueprintCallable)
	void EnableTick();

	UFUNCTION(BlueprintPure)
	static bool IsNewMatchmakingPortalUIEnabled();

	UFUNCTION(BlueprintCallable)
	void LoadAndCreateHUDWidget();

	UFUNCTION(BlueprintCallable)
	void PortalInteract(const FPortalMatchmakingData& MatchmakingData);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateHUDWidget();

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnHUDShow OnHUDShow;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnWidgetUpdate OnWidgetUpdate;

	UPROPERTY(BlueprintReadOnly, Export, Category="HeaderDescriptionHUDComponent", meta=(EditInline="true"))
	UUserWidget* LoadedHUDWidget;

protected:
	UPROPERTY(BlueprintReadWrite, Category="HeaderDescriptionHUDComponent")
	uint8 bDesiredVisibility : 1;

	UPROPERTY(BlueprintReadWrite, Category="HeaderDescriptionHUDComponent")
	uint8 bHUDAlreadyExists : 1;

};

