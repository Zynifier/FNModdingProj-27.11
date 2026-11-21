// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "FortTooltipManager.generated.h"

class AActor;
class APlayerController;
class UAbilitySystemComponent;
class UFortRegisteredPlayerInfo;
class UFortTooltip;
class UFortTooltipContext;
class UObject;

USTRUCT()
struct FFortTooltipMapEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortTooltipMapEntry", meta=(AllowAbstract))
	TSubclassOf<UObject> ObjectClass;

	UPROPERTY(EditDefaultsOnly, Category="FortTooltipMapEntry")
	TSubclassOf<UObject> SecondaryObjectClass;

	UPROPERTY(EditDefaultsOnly, Category="FortTooltipMapEntry")
	TSubclassOf<UFortTooltip> TooltipClass;

};

USTRUCT(BlueprintType)
struct FFortTooltipValueData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltip")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltip")
	FText FormattedValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltip")
	FText ExplanationText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltip")
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltip")
	FGameplayTagContainer StateTags;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortTooltipContext : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tooltips")
	static UFortTooltipContext* SpawnTooltipContext();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tooltips")
	static UFortTooltipContext* SpawnTooltipContext_Advanced(const TSubclassOf<UFortTooltipContext>& TooltipContextClass);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tooltips", meta=(WorldContext="WorldContextObject"))
	static UFortTooltipContext* SpawnTooltipContextWithNetID(UObject* WorldContextObject, const FUniqueNetIdRepl& UniqueID);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tooltips", meta=(WorldContext="WorldContextObject"))
	static UFortTooltipContext* SpawnTooltipContextWithNetID_Advanced(const TSubclassOf<UFortTooltipContext>& TooltipContextClass, UObject* WorldContextObject, const FUniqueNetIdRepl& UniqueID);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tooltips")
	static UFortTooltipContext* SpawnTooltipContextWithSource(APlayerController* SourcePlayerController);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tooltips")
	static UFortTooltipContext* SpawnTooltipContextWithSource_Advanced(const TSubclassOf<UFortTooltipContext>& TooltipContextClass, APlayerController* SourcePlayerController);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="Tooltip|Context")
	TWeakObjectPtr<UAbilitySystemComponent> SourceAbilitySystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="Tooltip|Context")
	TWeakObjectPtr<UAbilitySystemComponent> DestAbilitySystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltip|Context")
	int32 TreatAsLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltip|Context")
	FGameplayTagContainer TagContainer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltip|Context")
	TObjectPtr<UObject> ComparisonObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltip|Context")
	TObjectPtr<UFortRegisteredPlayerInfo> PlayerInfo;

};

UCLASS(MinimalAPI)
class UFortTooltipManager : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TMap<TSubclassOf<UObject>, TObjectPtr<UFortTooltip>> Tooltips;

	UPROPERTY()
	TWeakObjectPtr<AActor> DamageRecieverProxy;

};

UCLASS()
class UFortTooltipMap : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortTooltipMap")
	TArray<FFortTooltipMapEntry> Mapping;

};

