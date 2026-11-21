// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/SoftObjectPath.h"
#include "Creative/FortCreativeTags.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "Items/FortAccountItemDefinition.h"
#include "Items/FortPlaysetSettings.h"
#include "Items/FortPlaysetStreamingData.h"
#include "LevelSaveRecordProvider.h"
#include "FortPlaysetItemDefinition.generated.h"

class AActor;
class AFortMinigame;
class UFortPlaysetItemDefinition;
class UFortPlaysetPropItemDefinition;
class ULevelSaveRecord;
class ULevelSaveRecordCollection;
class ULevelStreamingDynamic;
class UObject;
class UWorld;

USTRUCT()
struct FFortPreviewActorData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortPreviewActorData")
	TSoftClassPtr<AActor> ActorClass;

	UPROPERTY(VisibleAnywhere, Category="FortPreviewActorData")
	FVector RelativeLocation;

	UPROPERTY(VisibleAnywhere, Category="FortPreviewActorData")
	FRotator RelativeRotation;

	UPROPERTY(VisibleAnywhere, Category="FortPreviewActorData")
	float InfluenceDistance;

	UPROPERTY(VisibleAnywhere, Category="FortPreviewActorData")
	int32 ActorTemplateID;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortPlaysetItemDefinition : public UFortAccountItemDefinition, public ILevelSaveRecordProvider, public IFortCreativeTagsBearer, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Playspace", meta=(WorldContext="WorldContextObject"))
	static FVector AdjustToFinalLocation(UObject* WorldContextObject, UFortPlaysetItemDefinition* Playset, FVector BaseLocation, FRotator Rotation);

#if WITH_EDITOR
	UFUNCTION(BlueprintPure, Category="Playset")
	FName GetPlaysetName() const;
#endif

	UFUNCTION(BlueprintCallable, Category="PvP|Experimental", meta=(WorldContext="WorldContextObject"))
	static void SpawnActorsInPlayset(AActor* WorldContextObject, UFortPlaysetItemDefinition* Playset);

	UFUNCTION(BlueprintCallable, Category="PvP|Experimental", meta=(WorldContext="WorldContextObject"))
	static ULevelStreamingDynamic* SpawnPlayset(AActor* WorldContextObject, const UFortPlaysetItemDefinition* Playset, FVector Location, FRotator Rotation, FFortPlaysetStreamingData& OutLevelData);

	UFUNCTION(BlueprintCallable, Category="PvP|Experimental", meta=(WorldContext="WorldContextObject"))
	static ULevelStreamingDynamic* SpawnPlaysetFromStruct(AActor* WorldContextObject, const FFortPlaysetStreamingData& LevelData);

	UPROPERTY(EditDefaultsOnly, Category="Playset")
	TSoftObjectPtr<UWorld> PlaysetToSpawn;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Playset", meta=(DisplayName="Source Map"))
	TSoftObjectPtr<UWorld> TemplateMap;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Playset", meta=(MustImplement="/Script/FortniteGame.LevelSaveSpawnable"))
	TSoftClassPtr<AActor> SourceActorBlueprint;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="Playset")
	FString OptionFullSavePath;
#endif

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset", meta=(MustImplement="/Script/FortniteGame.LevelSaveSpawnable"))
	TArray<TSoftClassPtr<AActor>> ActorVariants;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset", meta=(ClampMin="1"))
	int32 SizeX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset", meta=(ClampMin="1"))
	int32 SizeY;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset", meta=(ClampMin="1"))
	int32 SizeZ;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset")
	float ZSnapTolerance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset")
	EPlaysetOffsetType OffsetType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset")
	bool bUseLocationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset")
	bool bUseRelocationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset")
	FRotator DefaultRotation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset", meta=(AssetBundles="Server"))
	TSoftClassPtr<AFortMinigame> MinigameClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset")
	uint8 bAdjustForWorldCollision : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset")
	uint8 bUsePlaysetProps : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset")
	FString DocumentationUrl;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset", meta=(EditCondition="bUseLocationOffset"))
	FVector LocationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playset", meta=(EditCondition="bUseRelocationOffset"))
	FVector RelocationOffset;

private:
	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="Creative", meta=(Patchable, ShowOnlyInnerProperties))
	FFortCreativeTagsHelper CreativeTagsHelper;

	UPROPERTY()
	TObjectPtr<ULevelSaveRecord> LevelSaveRecord;

	UPROPERTY()
	TObjectPtr<ULevelSaveRecordCollection> PlaysetPropLevelSaveRecordCollection;

	UPROPERTY(VisibleAnywhere, AdvancedDisplay, Category="Playset")
	TMap<TSoftClassPtr<AActor>, int32> ActorClassCount;

	UPROPERTY(VisibleAnywhere, AdvancedDisplay, Category="Playset")
	TArray<TSoftObjectPtr<UFortPlaysetPropItemDefinition>> AssociatedPlaysetProps;

	UPROPERTY(VisibleAnywhere, AdvancedDisplay, Category="Playset")
	TArray<FFortPreviewActorData> PreviewActorData;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, AdvancedDisplay, Category="Playset")
	TArray<FSoftObjectPath> ActorRecordObjectReferences;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FName PlaysetName;
#endif

};

