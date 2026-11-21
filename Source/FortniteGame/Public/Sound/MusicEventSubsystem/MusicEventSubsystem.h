// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UObject/SoftObjectPath.h"
#include "Sound/MusicEventSubsystem/MusicEventTypes.h"
#include "MusicEventSubsystem.generated.h"

class UAudioComponent;
class UDataRegistry;
class UMusicEventInstance;
class UMusicEventSubsystemData;
class UMusicEventSubsystemDebugWidget;
class USoundBase;
class USynthComponent;

UCLASS(Config=Game, meta=(DisplayName="Music Event Subsystem"))
class UMusicEventSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Audio", meta=(AdvancedDisplay="2", CPP_Default_EventBehaviorTags="()"))
	UAudioComponent* AddEvent(USoundBase* Asset, FGameplayTag EventTag, FGameplayTagContainer EventBehaviorTags);

	UFUNCTION(BlueprintCallable, Category="Audio", meta=(AdvancedDisplay="2", CPP_Default_EventBehaviorTags="()"))
	void AddEventByComponent(UAudioComponent* Component, FGameplayTag EventTag, FGameplayTagContainer EventBehaviorTags);

	UFUNCTION(BlueprintCallable, Category="Audio", meta=(AdvancedDisplay="2", CPP_Default_EventBehaviorTags="()"))
	void AddEventBySynthComponent(USynthComponent* Component, FGameplayTag EventTag, FGameplayTagContainer EventBehaviorTags);

	UFUNCTION(BlueprintCallable)
	void ChangeEventCategory(UAudioComponent* Component, FGameplayTag EventTag);

	UFUNCTION(BlueprintCallable)
	void ChangeEventCategorySynthComponent(USynthComponent* Component, FGameplayTag EventTag);

	UFUNCTION(BlueprintCallable)
	void ChangeEventGroup(UAudioComponent* Component, FName GroupName);

	UFUNCTION(BlueprintCallable)
	void ChangeEventGroupSynthComponent(USynthComponent* Component, FName GroupName);

	UFUNCTION(BlueprintPure, Category="Audio")
	UMusicEventInstance* GetEventInstance(UAudioComponent* Component);

	UFUNCTION(BlueprintPure, Category="Audio")
	bool IsEnabled() const;

	UFUNCTION(BlueprintCallable, Category="Audio")
	void RemoveAllEvents(bool bPreviousWorldsOnly = false);

	UFUNCTION(BlueprintCallable, Category="Audio", meta=(GameplayTagFilter="MusicEventSubsystem"))
	void RemoveEvent(UAudioComponent* Component);

	UFUNCTION(BlueprintCallable, Category="Audio", meta=(GameplayTagFilter="MusicEventSubsystem"))
	void RemoveEventBySynthComponent(USynthComponent* Component);

	UFUNCTION(BlueprintCallable, Category="Audio")
	void RemoveEventCategory(FGameplayTag EventTag);

	UPROPERTY(Config, meta=(AllowedClasses="/Script/FortniteGame.MusicEventSubsystemData"))
	FSoftObjectPath SubsystemDataAssetPath;

	UPROPERTY(Transient)
	TObjectPtr<UMusicEventSubsystemData> SubsystemData;

private:
	UFUNCTION()
	void OnEventInstancePlaybackCompleted(UMusicEventInstance* Instance);

	UFUNCTION()
	void OnLoadingScreenComplete();

	UPROPERTY()
	TArray<FMusicEventData> EventDataArray;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UMusicEventInstance>> EventInstances;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UMusicEventInstance>> EventInstancesFadingOut;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<UMusicEventInstance>> TickingEventInstances;

	UPROPERTY(Transient, Export)
	TArray<TWeakObjectPtr<UAudioComponent>> AllComponents;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAudioComponent>> OwnedComponents;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UMusicEventSubsystemDebugWidget> DebugWidget;

};

UCLASS()
class UMusicEventSubsystemData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Event Data")
	TObjectPtr<UDataRegistry> EventDataRegistry;

	UPROPERTY(EditDefaultsOnly, Category="Event Behavior Tags", meta=(Categories="MusicEventSubsystem"))
	FGameplayTag AudioComponentOwnerTag;

	UPROPERTY(EditDefaultsOnly, Category="Event Behavior Tags", meta=(Categories="MusicEventSubsystem"))
	FGameplayTag PersistIntoFrontEnd;

	UPROPERTY(EditDefaultsOnly, Category="Event Behavior Tags", meta=(Categories="MusicEventSubsystem"))
	FGameplayTag CanRetriggerTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Debug Widget")
	TSubclassOf<UMusicEventSubsystemDebugWidget> DebugWidgetClass;

};

UCLASS()
class UMusicEventSubsystemDebugWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UMusicEventSubsystemDebugWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Setup")
	void SetEventInstances(const TArray<UMusicEventInstance*>& Instances);

};

