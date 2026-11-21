// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "Building/BuildingGameplayActor.h"
#include "FortAthenaPartyRiftPortal.generated.h"

class AActor;
class AFortPlayerController;
class AFortPlayerStateAthena;
class UCapsuleComponent;
class UPrimitiveComponent;
class UTexture2DDynamic;
class UUserWidget;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortAthenaPartyRiftPortal : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void AdjustBeaconCollisionHeight(float Distance);

	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	bool BlueprintDisplayMobileInteractPrompt() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	bool BlueprintUseMobileHighlight() const;

	UFUNCTION(BlueprintImplementableEvent)
	void CuratedPortalChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void DisplayNameChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void ErrorStateChanged();

	UFUNCTION(BlueprintCallable)
	FVector GetHUDPointerOrigin();

	UFUNCTION(BlueprintPure)
	FText GetPartyJoinPrompt() const;

	UFUNCTION(BlueprintPure)
	bool IsPartyJoinable() const;

	UFUNCTION(BlueprintPure)
	bool IsPartyJoinRequestable() const;

	UFUNCTION(BlueprintPure)
	bool IsPortalInteractable() const;

	UFUNCTION(BlueprintCallable)
	bool OnInteractWithPartyRiftPortal(AFortPlayerController* InteractingController);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMaxPartySizeChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPartyMembersChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OverlappingOnBeginPlay(AActor* Actor);

	UFUNCTION(BlueprintImplementableEvent)
	void OwningPlayerNetIdChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void PortalOpenChanged();

	UFUNCTION(BlueprintCallable)
	void ReleasePortal(const FString& Reason);

	UFUNCTION(BlueprintCallable)
	void SetHUDPointerOrigin(const FVector NewPointerOrigin);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowLongRangeInteractionUI(bool bShow, float InteractionOffset);

	UFUNCTION(BlueprintCallable)
	void UpdatePartyJoinInfo();

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="FortAthenaPartyRiftPortal")
	int32 PortalIndex;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Portal")
	FString OverrideImageURL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Interaction", meta=(EditCondition="bAllowInteract"))
	uint8 bForceUpdateInteraction : 1;

	UPROPERTY(BlueprintReadWrite, Category="FortAthenaPartyRiftPortal")
	bool bLocalPlayerInRange;

protected:
	UFUNCTION(BlueprintPure)
	FText GetCreatorName() const;

	UFUNCTION(BlueprintPure)
	const int32 GetCurrentPartySize() const;

	UFUNCTION(BlueprintPure)
	bool GetIsPublishedPortal() const;

	UFUNCTION(BlueprintPure)
	const int32 GetMaxPartySize() const;

	UFUNCTION(BlueprintPure)
	TArray<AFortPlayerStateAthena*> GetPartyMemberPlayerStateList() const;

	UFUNCTION(BlueprintPure)
	AFortPlayerStateAthena* GetPortalOwnerPlayerState() const;

	UFUNCTION(BlueprintPure)
	FText GetTagline() const;

	UFUNCTION(BlueprintPure)
	int32 GetThumbnailHeight() const;

	UFUNCTION(BlueprintPure)
	int32 GetThumbnailWidth() const;

	UFUNCTION(BlueprintPure)
	bool IsPlayerInOwnerParty(const AFortPlayerController* InteractingController) const;

	UFUNCTION(BlueprintPure)
	bool IsPortalOpen() const;

	UFUNCTION()
	void OnRep_bIsPublishedPortal();

	UFUNCTION()
	void OnRep_bPortalOpen();

	UFUNCTION()
	void OnRep_ErrorState();

	UFUNCTION()
	void OnRep_OwningPlayerNetId(const FUniqueNetIdRepl InOldOwningPlayerNetId);

	UFUNCTION(BlueprintImplementableEvent)
	void OnThumbnailTextureReady();

	UFUNCTION(BlueprintCallable)
	void SetInteractionDisplayWidget(UUserWidget* DisplayWidget);

	UFUNCTION(BlueprintCallable)
	void SetInteractionInteractComponent(UPrimitiveComponent* PrimitiveComponent);

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaPartyRiftPortal")
	FVector MarkerDetailsPointerOrigin;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaPartyRiftPortal", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> InteractComponent;

	UPROPERTY(Transient)
	FText SanitizedTagline;

	UPROPERTY(Transient)
	FText SanitizedCreatorName;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> InteractionDisplayWidget;

	UPROPERTY(BlueprintReadOnly, Config, Category="Portal")
	bool bPortalInteractDisabled;

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaPartyRiftPortal")
	bool bLocalClientLacksPermission;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaPartyRiftPortal")
	TObjectPtr<UTexture2DDynamic> ThumbnailTexture;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortAthenaPartyRiftPortal")
	TWeakObjectPtr<UCapsuleComponent> InteractIconPlacementCapsule;

private:
	UFUNCTION()
	void OnRep_MaxPartySize();

	UFUNCTION()
	void OnRep_PartyJoinInfoJSON();

	UFUNCTION()
	void OnRep_PartyMemberNetIdList();

	UFUNCTION(Server, Reliable)
	void ServerCacheMaxPartySize(const int32 NewMaxPartySize);

	UFUNCTION(Server, Reliable)
	void ServerCachePartyJoinInfo(const FString& NewPartyJoinInfo);

	UFUNCTION(Server, Reliable)
	void ServerCachePartyMemberNetIdList(const TArray<FUniqueNetIdRepl>& NewPartyMemberNetIdList);

	UFUNCTION(BlueprintCallable)
	void UpdateThumbnail();

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_ErrorState, Category="Portal", meta=(AllowPrivateAccess="true"))
	bool bInErrorState;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_OwningPlayerNetId, Category="Portal", meta=(AllowPrivateAccess="true"))
	FUniqueNetIdRepl OwningPlayerNetId;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bIsPublishedPortal)
	bool bIsPublishedPortal;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_bPortalOpen, Category="Portal", meta=(AllowPrivateAccess="true"))
	bool bPortalOpen;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStateAthena> CachedOwningPlayerState;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerStateAthena>> CachedPartyMemberPlayerStateList;

	UPROPERTY(ReplicatedUsing=OnRep_PartyJoinInfoJSON)
	FString PartyJoinInfoJSON;

	UPROPERTY(ReplicatedUsing=OnRep_MaxPartySize)
	int32 MaxPartySize;

	UPROPERTY(ReplicatedUsing=OnRep_PartyMemberNetIdList)
	TArray<FUniqueNetIdRepl> PartyMemberNetIdList;

	UPROPERTY(Replicated)
	int32 InitialDeploymentTime;

};

