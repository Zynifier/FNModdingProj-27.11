// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortPersistentResourceItemDefinition.generated.h"

class AActor;
class AFortItemPreviewActor;
class UFortPersistentResourceItemDefinition;
class UFortQuestItemDefinition;
class UTexture2D;

UCLASS(MinimalAPI, BlueprintType)
class UFortPersistentResourceItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FString GetStatName() const;

	UFUNCTION(BlueprintPure, Category="Event Item")
	bool IsEventItem() const;

	UPROPERTY(EditDefaultsOnly, Category="FortPersistentResourceItemDefinition")
	TSoftClassPtr<AFortItemPreviewActor> ItemPreviewActorClass;

	UPROPERTY(EditDefaultsOnly, Category="FortPersistentResourceItemDefinition")
	TSoftClassPtr<AActor> PreviewPrefabAssetClass;

protected:
	UPROPERTY(EditAnywhere, Category="Event Item")
	bool bIsEventItem;

	UPROPERTY(EditAnywhere, Category="Stats")
	FString StatName;

	UPROPERTY(EditAnywhere, Category="Stats")
	FString StatTotalName;

	UPROPERTY(EditDefaultsOnly, Category="Exclusive Item")
	FText ExclusiveDesciption;

	UPROPERTY(EditDefaultsOnly, Category="Exclusive Item")
	TSoftObjectPtr<UTexture2D> ExclusiveIcon;

	UPROPERTY(EditDefaultsOnly, Category="Toast Display")
	TArray<TSoftObjectPtr<UFortQuestItemDefinition>> QuestsRequiredToDisplayToast;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Athena Item")
	bool bIsAthenaOnlyItem;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Event Granter")
	bool bIsEventCurrencyGranter;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Event Granter", meta=(EditCondition="bIsEventGranterCurrency"))
	TSoftObjectPtr<UFortPersistentResourceItemDefinition> GrantedCurrency;
#endif

};

