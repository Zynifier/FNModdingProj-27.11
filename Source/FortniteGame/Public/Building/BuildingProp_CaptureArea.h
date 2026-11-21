// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingProp.h"
#include "FortItemVariantHandle.h"
#include "BuildingProp_CaptureArea.generated.h"

class AActor;
class AController;
class AFortPickup;
class AFortPlayerController;
class AFortPlayerState;
class UCaptureComponent;
class UFortWidgetComponent;
class UPrimitiveComponent;
class UTexture2D;

UENUM(BlueprintType)
enum class ECaptureAreaItemFilters : uint8
{
	None = 0,
	Both = 1,
	ForPeriodicScoring = 2,
	ToTakeControl = 3,
};

UENUM(BlueprintType)
enum class EPlayerCaptureKnobOptions : uint8
{
	Off = 0,
	EachPlayer = 1,
	OnePlayerPerTeam = 2,
	OwningTeam = 3,
};

USTRUCT(BlueprintType)
struct FCaptureAreaTeamInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CaptureAreaTeamInfo")
	TArray<TObjectPtr<AFortPlayerController>> Players;

	UPROPERTY(BlueprintReadOnly, Category="CaptureAreaTeamInfo")
	uint8 InsideTeamIndex;

};

USTRUCT()
struct FCaptureHandle
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FCaptureIconData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CaptureIconData")
	TSoftObjectPtr<UTexture2D> IconTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CaptureIconData")
	float TextScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CaptureIconData")
	float VisibleDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CaptureIconData")
	bool bDisplaysDistanceText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CaptureIconData")
	bool bDisplaysOwningTeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CaptureIconData")
	bool bRequiresLineOfSight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CaptureIconData")
	bool bShowOffscreenArrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CaptureIconData")
	bool bEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CaptureIconData")
	TArray<FString> TextOverrides;

};

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_CaptureArea : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureArea")
	void BindToControllerInventoryChangedEvent(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureArea")
	int32 CaptureItemsFromPickup(const TArray<FItemVariantHandle>& ItemsToCapture, AFortPickup* Pickup, int32& AddedScore);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureArea")
	int32 CaptureItemsFromPlayer(bool bRemoveOnFound, const TArray<FItemVariantHandle>& ItemsToCapture, AFortPlayerController* PlayerController, int32 AmountToRemove, int32& AddedScore);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="InWorldCaptureIcon")
	void GetCaptureIconData(FCaptureIconData& OutCaptureIconData) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnOverlappedPlayerInventoryChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOverlappedPlayerInventoryValidated(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureComponent")
	void OnPlayerChangedTeam(AFortPlayerState* PlayerState, uint8 NewTeam, uint8 OldTeam, bool bTeamChangedWithoutRespawn);

	UFUNCTION(BlueprintImplementableEvent, Category="CaptureComponent")
	void OnPlayerEnterZone(AFortPlayerController* PlayerController, const bool bIsFirst);

	UFUNCTION(BlueprintImplementableEvent, Category="CaptureComponent")
	void OnPlayerLeavesZone(AFortPlayerController* PlayerController, const bool bIsLast);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureComponent")
	void RegisterPlayerInsideArea(AFortPlayerController* PlayerInside);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureArea")
	void RemoveItemsFromPlayer(const TArray<FItemVariantHandle>& ItemsToCapture, AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureArea")
	void UnbindAllControllersToInventoryChangedEvent();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureArea")
	void UnbindToControllerInventoryChangedEvent(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureComponent")
	void UnregisterPlayerInsideArea(AFortPlayerController* OldPlayerInside);

	UPROPERTY(BlueprintReadOnly, Transient, Category="CaptureArea")
	TArray<FCaptureAreaTeamInfo> CaptureAreaTeamsInfo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Export, Category="CaptureArea", meta=(EditInline="true"))
	TObjectPtr<UCaptureComponent> CaptureComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Export, Category="InWorldCaptureIcon", meta=(EditInline="true"))
	TObjectPtr<UFortWidgetComponent> CaptureIconWidgetComponent;

protected:
	UFUNCTION(BlueprintCallable, Category="CaptureArea")
	void BindOrUnbindOnPlayerTeamReplicated(AFortPlayerState* PlayerState, bool bBind);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnPlayerTeamReplicated();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnCaptureAreaOwnerChanged(AFortPlayerController* NewOwner);

	UFUNCTION()
	virtual void OnFortPawnRegisteredInsideAreaDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTeamsInfoChanged();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureArea")
	void UnregisterAllRegisteredPlayerInsideArea();

private:
	UPROPERTY(Transient)
	TMap<TObjectPtr<AFortPlayerController>, FCaptureHandle> InventoryChangedHandlesMap;

};

