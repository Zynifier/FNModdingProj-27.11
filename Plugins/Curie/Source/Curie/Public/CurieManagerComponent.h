// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "CurieManagerComponent.generated.h"

class UCurieManagerComponent;
class UCurieManagerComponentConfig;

UENUM()
enum class ECurieManagerComponentPriority : uint8
{
	Priority_1 = 1,
	Priority_2 = 2,
	Priority_3 = 3,
	Priority_4 = 4,
	Priority_5 = 5,
	Priority_6 = 6,
	Priority_7 = 7,
	Priority_8 = 8,
	Priority_9 = 9,
	Priority_10 = 10,
	Priority_Default = 11,
};

USTRUCT()
struct CURIE_API FCurieManagerComponentEntry : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="CurieManagerComponentEntry")
	bool bIsActive;

	UPROPERTY(EditDefaultsOnly, Category="CurieManagerComponentEntry")
	ECurieManagerComponentPriority Priority;

	UPROPERTY(EditDefaultsOnly, Category="CurieManagerComponentEntry")
	TSubclassOf<UCurieManagerComponent> ManagerType;

	UPROPERTY(EditDefaultsOnly, Category="CurieManagerComponentEntry")
	TObjectPtr<UCurieManagerComponentConfig> Config;

};

UCLASS(Abstract)
class CURIE_API UCurieManagerComponent : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UCurieManagerComponentConfig> CachedConfig;

};

UCLASS(Abstract)
class CURIE_API UCurieManagerComponentConfig : public UPrimaryDataAsset, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, Category="CurieManagerComponentConfig", meta=(Patchable))
	FName ConfigName;

	UPROPERTY(EditDefaultsOnly, Category="CurieManagerComponentConfig", meta=(Categories="Curie.Manager", Patchable))
	FGameplayTag ConfigTag;

};

UINTERFACE()
class CURIE_API UCurieManagerComponentInterface : public UInterface
{
	GENERATED_BODY()
};

class CURIE_API ICurieManagerComponentInterface
{
	GENERATED_BODY()

};

