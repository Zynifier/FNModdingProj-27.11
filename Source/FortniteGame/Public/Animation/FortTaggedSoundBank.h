// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortTaggedSoundBank.generated.h"

class UFortTaggedSoundBank;
class USoundAttenuation;
class USoundBase;
class USoundClass;

USTRUCT()
struct FFortTaggedSoundCue
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	FGameplayTagQuery Requirements;

	UPROPERTY(EditAnywhere, Category="Settings")
	TObjectPtr<USoundBase> Sound;

};

USTRUCT()
struct FTaggedSoundBankResponseList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Config")
	TArray<FFortTaggedSoundCue> CueList;

};

UCLASS(BlueprintType)
class UFortTaggedSoundBank : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	USoundBase* GetSoundToPlay(const FGameplayTag& Tag, const FGameplayTagContainer& Context);

	UFUNCTION(BlueprintPure)
	USoundBase* GetSoundToPlayByExactMatch(const FGameplayTag& Tag, const FGameplayTagContainer& Context);

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Sounds", meta=(DisplayName="Sounds"))
	TMap<FGameplayTag, FTaggedSoundBankResponseList> ResponseMap;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Config")
	TObjectPtr<UFortTaggedSoundBank> ParentBank;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Config")
	TArray<TObjectPtr<USoundClass>> AllowedSoundClasses;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Config")
	TArray<TObjectPtr<USoundAttenuation>> AllowedAttenuationSettings;
#endif

	UPROPERTY()
	TMap<FGameplayTag, FTaggedSoundBankResponseList> FlattenedResponseMap;

};

