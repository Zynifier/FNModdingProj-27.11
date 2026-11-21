// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "TagTableManager.generated.h"

class UDataTable;

USTRUCT()
struct FManagedGameplayTagDataTableItem
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="ManagedGameplayTagDataTableItem")
	FGameplayTag RootTag;

	UPROPERTY(EditAnywhere, Category="ManagedGameplayTagDataTableItem")
	TObjectPtr<UDataTable> DataTable;

};

UCLASS()
class EPICGAMEPLAYSTATSRUNTIME_API UGameplayTagTableManager : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="GameplayTagTableManager")
	TArray<FManagedGameplayTagDataTableItem> Tables;

};

