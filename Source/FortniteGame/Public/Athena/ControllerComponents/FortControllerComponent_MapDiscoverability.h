// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Athena/ControllerComponents/FortControllerComponent_HasCoupledWidgets.h"
#include "FortControllerComponent_MapDiscoverability.generated.h"

class UFortControllerComponent_MapDiscoverability;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMaterialParameterCollection;
class USoundCue;
class UTextureRenderTarget2D;

UENUM()
enum class EPoiDiscoveredState : uint8
{
	Undiscovered = 0,
	Discovered = 1,
	ForceDiscovered = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStencilMIDCreated, UMaterialInstanceDynamic*, StencilMID);

USTRUCT()
struct FPoiDiscoverabilityDataEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag PoiTag;

	UPROPERTY()
	EPoiDiscoveredState DiscoveredState;

	UPROPERTY()
	bool bWasInitiallyDiscovered;

protected:
	UPROPERTY()
	uint8 VisitCounter;

};

USTRUCT()
struct FPoiDiscoverabilityDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FPoiDiscoverabilityDataEntry> Entries;

	UPROPERTY(NotReplicated, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_MapDiscoverability> Owner;

};

USTRUCT()
struct FPoiDiscoverabilityPlayerFacingData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText PlayerFacingText;

	UPROPERTY()
	TSoftObjectPtr<USoundCue> SoundCue;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_MapDiscoverability : public UFortControllerComponent_HasCoupledWidgets
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void EventsReadyStub(const TArray<FString>& Events);

	UFUNCTION(BlueprintPure)
	const FText& GetMapTextForLocation(const FGameplayTag& Location) const;

	UFUNCTION(BlueprintPure)
	UMaterialInstanceDynamic* GetStencilMID() const;

	UFUNCTION()
	void PlaylistLoadedStub(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION(BlueprintCallable)
	void SetSuppressDiscoveryEvents(bool bSuppress);

protected:
	UPROPERTY(EditAnywhere, Category="Discovery")
	TObjectPtr<UMaterialParameterCollection> DiscoverabilityMPC;

	UPROPERTY(EditAnywhere, Category="Discovery")
	FScalableFloat DiscoveryUnmaskDuration;

	UPROPERTY(EditAnywhere, Category="Discovery")
	bool bFlipYInput;

	UPROPERTY(EditAnywhere, Category="Discovery")
	float DiscoveryUnmaskUpdateRate;

	UPROPERTY(EditAnywhere, Category="Discovery")
	TSoftObjectPtr<UTextureRenderTarget2D> DiscoveryRenderTarget;

	UPROPERTY(EditAnywhere, Category="Discovery")
	TSoftObjectPtr<UMaterialInterface> StencilMaterial;

	UPROPERTY(Replicated)
	FPoiDiscoverabilityDataArray DiscoveredData;

	UPROPERTY(BlueprintAssignable)
	FOnStencilMIDCreated OnStencilMIDCreated;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> StencilMID;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInterface> StencilInstance;

	UPROPERTY(Transient)
	TObjectPtr<UTextureRenderTarget2D> DiscoveryRenderTargetInstance;

private:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void CancelTeleportToAllLocations();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DiscoverAllAreas();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DiscoverAllLandmarks();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DiscoverAllPois();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetDiscoverStatusByTag(const FString& Tag, bool bDiscovered);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TeleportToAllLocations(float DelayBetween);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void UndiscoverAllAreas();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void UndiscoverAllLandmarks();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void UndiscoverAllPois();

};

