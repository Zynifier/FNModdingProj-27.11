// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UI/FortMiniMapComponent.h"
#include "FortMiniMapComponent_Discoverable.generated.h"

class AFortPlayerController;
class UObject;
class UTexture2D;
enum class EMiniMapComponentDiscoverableVisibility : uint8;

UENUM(BlueprintType)
enum class EMiniMapComponentDiscoverableVisibility : uint8
{
	/** Used by individual players to mark that they do NOT have an override visibility and that the default visibility should be used. */
	Unset = 0,
	/** This icon should NOT be visible. */
	NotVisible = 1,
	/** This icon should be visible, but marked as undiscovered (this is normally done with a ? icon.) */
	Visible_NotDiscovered = 2,
	/** This icon should be visible and should use the discovered icon. */
	Discovered = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMiniMapComponentDiscoverable_OnPlayerVisibilityChanged, AFortPlayerController*, PlayerController, EMiniMapComponentDiscoverableVisibility, NewVisibility);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "VisibleDistance", "Trigger"), meta=(BlueprintSpawnableComponent))
class UFortMiniMapComponent_Discoverable : public UFortMiniMapComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void DisableDefaultVisibilityCanChangeAtRuntime();

	UFUNCTION(BlueprintPure)
	EMiniMapComponentDiscoverableVisibility GetDefaultVisibility();

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool GetDefaultVisibilityCanChangeAtRuntime() const;

	UFUNCTION(BlueprintPure)
	EMiniMapComponentDiscoverableVisibility GetPlayersSetVisibility(const AFortPlayerController* PlayerController) const;

	UFUNCTION(BlueprintPure)
	EMiniMapComponentDiscoverableVisibility GetVisibilityForPlayer(const AFortPlayerController* PlayerController) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetDefaultVisibility(const EMiniMapComponentDiscoverableVisibility InVisibility, const bool bClearAllPlayerVisibilityOverrides = false);

	UFUNCTION(BlueprintCallable)
	void SetMiniMapDiscoveredIcon(UObject* MiniMapIcon);

	UFUNCTION(BlueprintCallable)
	void SetMiniMapDiscoveredIconScale(const FVector2D& IconScale);

	UFUNCTION(BlueprintCallable)
	void SetMiniMapNotDiscoveredIconScale(const FVector2D& IconScale);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetVisibilityForPlayer(AFortPlayerController* PlayerController, EMiniMapComponentDiscoverableVisibility Visibility);

	UPROPERTY(BlueprintAssignable)
	FMiniMapComponentDiscoverable_OnPlayerVisibilityChanged OnPlayerVisibilityChanged;

private:
	UFUNCTION()
	void OnRep_NotDiscoveredIcon();

	UFUNCTION()
	void OnRep_NotDiscoveredIconScale();

	UPROPERTY(EditDefaultsOnly, Replicated, Category="FortMiniMapComponent_Discoverable", meta=(AllowPrivateAccess))
	EMiniMapComponentDiscoverableVisibility DefaultVisibility;

	UPROPERTY(EditDefaultsOnly, Category="FortMiniMapComponent_Discoverable", meta=(AllowPrivateAccess))
	bool bDefaultVisibilityCanChangeAtRuntime;

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_NotDiscoveredIconScale, Category="FortMiniMapComponent_Discoverable", meta=(AllowPrivateAccess))
	FVector2D NotDiscoveredIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing=OnRep_NotDiscoveredIcon, Category="FortMiniMapComponent_Discoverable", meta=(AllowPrivateAccess))
	TObjectPtr<UTexture2D> NotDiscoveredIcon;

};

