// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "Components/CustomFeedMessageContext.h"
#include "Components/FortPlayerStateComponent.h"
#include "FortPlayerStateComponent_CustomFeedMessage.generated.h"

class UFortCustomFeedMessageConfig;
class UFortCustomFeedMessageGeneratorBase;
class USoundBase;

UENUM()
enum class ECustomFeedFilterParticipantNames : uint8
{
	NoFiltering = 0,
	AllPlayers = 1,
};

UCLASS()
class UFortCustomFeedMessageConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="FortCustomFeedMessageConfig")
	TMap<FGameplayTag, TObjectPtr<UFortCustomFeedMessageGeneratorBase>> FeedMessageGeneratorsByID;

};

UCLASS(Abstract, EditInlineNew, BlueprintType)
class UFortCustomFeedMessageGeneratorBase : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Name Filters")
	ECustomFeedFilterParticipantNames FilteredParticipantNamePolicy;

};

UCLASS(BlueprintType)
class UFortCustomFeedMessageWith2DAudio : public UFortCustomFeedMessageGeneratorBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Feed Message")
	FText FeedMessageFormat;

	UPROPERTY(EditDefaultsOnly, Category="Audio")
	TObjectPtr<USoundBase> OnTriggeredAudio;

};

UCLASS(BlueprintType)
class UFortCustomFeedMessageWith3DAudio : public UFortCustomFeedMessageWith2DAudio
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Audio")
	FVector AdditionalAudioOffset;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortPlayerStateComponent_CustomFeedMessage : public UFortPlayerStateComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleNetMulticastTriggerCustomFeedMessage(const FGameplayTag CustomFeedMessageGeneratorID);

	UFUNCTION()
	void HandleNetMulticastTriggerCustomFeedMessageWithContext(const FGameplayTag CustomFeedMessageGeneratorID, FCustomFeedMessageContext Context);

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerStateComponent_CustomFeedMessage")
	TArray<TSoftObjectPtr<UFortCustomFeedMessageConfig>> CustomFeedMessageConfigs;

	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UFortCustomFeedMessageGeneratorBase>> CustomFeedMessageGeneratorsInternal;

};

