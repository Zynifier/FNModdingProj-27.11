// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Creative/CreativeEditablePropertyInterface.h"
#include "Creative/FortCreativeToyOptionInterface.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortGameplayMessageComponentBase.generated.h"

class UUserWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnChannelIdsReplicated);

UCLASS(MinimalAPI)
class UFortGameplayMessageComponentBase : public UActorComponent, public ILevelSaveSpawnable, public IFortCreativeToyOptionInterface, public ICreativeEditablePropertyInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FGameplayTagContainer GetChannelId() const;

	UFUNCTION(BlueprintPure)
	FText GetDisabledReason() const;

	UFUNCTION(BlueprintPure)
	int32 GetMessageChannelIndex() const;

	UFUNCTION(BlueprintPure)
	FText GetMessageDescription() const;

	UFUNCTION(BlueprintPure)
	FText GetMessageName() const;

	UFUNCTION(BlueprintPure)
	bool IsChannelIdSet() const;

	UFUNCTION(BlueprintPure)
	bool IsEnabled() const;

	UFUNCTION(BlueprintCallable)
	void SetChannelId(const FGameplayTagContainer& NewChannelIds);

	UPROPERTY(BlueprintAssignable)
	FOnChannelIdsReplicated OnChannelIdsReplicated;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameplayMessageComponentBase")
	FGameplayTagContainer FilterTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameplayMessageComponentBase", meta=(Categories="Creative"))
	FGameplayTagQuery RequiredFilterTagQuery;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Message")
	FText MessageName;

	UPROPERTY(EditDefaultsOnly, Category="Message")
	FText MessageDescription;

	UPROPERTY(EditInstanceOnly, SaveGame, ReplicatedUsing=OnRep_ChannelIds, Category="Channel", meta=(Categories="Creative.Message.Channel"))
	FGameplayTagContainer ChannelIds;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	int32 WeightOffset;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UUserWidget> EditWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameplayMessageComponentBase")
	FGameplayTagContainer Tags;

private:
	UFUNCTION()
	void OnRep_ChannelIds();

};

