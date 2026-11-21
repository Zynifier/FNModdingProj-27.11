// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Creative/Components/CreativeRegisteredPlayersManagerComponent.h"
#include "Creative/Components/CreativeRegisteredPlayersProxyInterface.h"
#include "Creative/FortCreativeDeviceProp.h"
#include "CreativeAudioMixerDevice.generated.h"

class AController;
class ACreativeAudioMixerReplicationProxy;
class ACreativePlayerReplicationProxy;
class AFortPlayerState;
class UCreativeProxyManagerComponent;
class UCreativeRegisteredPlayersManagerComponent;
class UFortActorOptionsComponent;
class UFortMinigameProgressComponent;
class USoundControlBus;
class USoundControlBusMix;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ACreativeAudioMixerDevice : public AFortCreativeDeviceProp, public ICreativeRegisteredPlayersProxyInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ActivateMix();

	UFUNCTION(BlueprintCallable)
	void DeactivateMix();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	TObjectPtr<USoundControlBusMix> Mix;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic", meta=(EditCondition="Mix == nullptr"))
	TObjectPtr<USoundControlBus> Bus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic", meta=(ClampMax="1.000000", ClampMin="0.000000", DisplayAfter="Bus", EditCondition="Mix == nullptr"))
	float FaderValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Basic")
	ECreativeRegisteredPlayerGroups CanBeHeardBy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Activation")
	bool bActivateInEditMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions|Activation")
	bool bActivateOnGameStart;

private:
	UFUNCTION()
	void OnAllPlayersUnregistered();

	UFUNCTION()
	void OnMinigameEnded();

	UFUNCTION()
	void OnMinigameStarted();

	UFUNCTION()
	void OnPlayerAdded(FUniqueNetIdRepl NetId, bool bIsLocalPlayer);

	UFUNCTION()
	void OnPlayerRegistered(const AFortPlayerState* PlayerState);

	UFUNCTION()
	void OnPlayerUnregistered(const AFortPlayerState* PlayerState);

	UFUNCTION()
	void OnPreAnyPropertyChanged();

	UFUNCTION()
	void OnProxyDataChanged(ACreativePlayerReplicationProxy* ProxyData);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCreativeProxyManagerComponent> CreativeProxyManagerComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMinigameProgressComponent> FortMinigameProgressComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCreativeRegisteredPlayersManagerComponent> CreativeRegisteredPlayersManagerComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortActorOptionsComponent> FortActorOptionsComponent;

	UPROPERTY(Transient)
	bool bCachedIsActive;

	UPROPERTY(Transient)
	TObjectPtr<AController> CachedInstigator;

	UPROPERTY(Transient)
	TObjectPtr<ACreativeAudioMixerReplicationProxy> ClientCachedProxy;

	UPROPERTY(Transient)
	TObjectPtr<USoundControlBusMix> CachedBusMix;

	UPROPERTY(Transient)
	FName CachedBusMixName;

	UPROPERTY(Transient)
	TArray<FUniqueNetIdRepl> RegisteredPlayerIds;

	UPROPERTY(Transient)
	TArray<FUniqueNetIdRepl> NonRegisteredPlayerIds;

	UPROPERTY(Transient)
	bool bHasUpdatedStateInEditMode;

	UPROPERTY(Transient)
	bool bHasUpdatedStateInGameplay;

};

