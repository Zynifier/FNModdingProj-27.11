// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/NoExportTypes.h"
#include "UObject/PrimaryAssetId.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "FortPlaylistUserOptions.h"
#include "DAD_CreativeUserOptions.generated.h"

class UDAD_CreativeUserOptions;
enum class EDataAssetDirectoryUpdateStatus : uint8;

USTRUCT(BlueprintType)
struct FDAD_BaseCreativeUserOption
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DAD_BaseCreativeUserOption")
	FString Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DAD_BaseCreativeUserOption")
	FText DisplayName;

};

UCLASS()
class UDAD_CreativeUserOptions : public UPrimaryDataAsset, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="DAD_CreativeUserOptions", meta=(Patchable))
	FName CreativeUserOptionsListName;

};

UCLASS(Config=Game)
class UDAD_CreativeUserOptionsCollection : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UDAD_CreativeUserOptions>> CreativeUserOptionAssets;

};

UCLASS(BlueprintType)
class UPlaylistUserOptionDAD : public UPlaylistUserOptionEnum
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Init();

	UFUNCTION()
	void OnDADUpdateComplete(EDataAssetDirectoryUpdateStatus Result, const TArray<FPrimaryAssetId>& PatchedAssetIds);

	UFUNCTION()
	virtual void UpdateData();

private:
	UPROPERTY(EditDefaultsOnly, Category="PlaylistUserOptionDAD")
	FName CreativeUserOptionsListName;

};

