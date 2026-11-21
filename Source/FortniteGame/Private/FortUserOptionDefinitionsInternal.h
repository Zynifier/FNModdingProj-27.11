// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/NoExportTypes.h"
#include "FortUserOptionDefinitions.h"
#include "FortUserOptionDefinitionsInternal.generated.h"

class UBlueprint;
class UPlaylistUserOptionBase;
class UPlaylistUserOptions;
class UPlaylistUserOptionsFilter;

UCLASS(BlueprintType, Blueprintable, SparseClassDataType=UserOptionDefinitionContainer)
class AUserOptionDefinitionTestActor : public AActor
{
	GENERATED_BODY()

};

UCLASS(Transient)
class UUserOptionDefinitionContainerProxy : public UObject, public IUserOptionDefinitionContainerInterface
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class UUserOptionDefinitionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="UserOptions|MigrateLegacyData")
	static void FixupLegacyUserOptionPropertyFlags(UBlueprint* Blueprint);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="UserOptions|MigrateLegacyData")
	static void FixupUserOptionEventNames(UBlueprint* Blueprint, const bool bSkipPropertyRename = false);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="UserOptions|MigrateLegacyData")
	static void FixupUserOptionPropertyFlags(UBlueprint* Blueprint);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="UserOptions|MigrateLegacyData", meta=(CPP_Default_Config="()"))
	static void MigrateLegacyChannelsForBlueprint(UBlueprint* Blueprint, const FUserOptionMigrateLegacyDataConfig Config);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="UserOptions|MigrateLegacyData", meta=(OptionToPropertyNameOverrides="()", CPP_Default_Config="()"))
	static void MigrateLegacyOptionsForBlueprint(UBlueprint* Blueprint, const TMap<FName, FName> OptionToPropertyNameOverrides, const FUserOptionMigrateLegacyDataConfig Config);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="UserOptions|MigrateLegacyData", meta=(OptionToPropertyNameOverrides="()", CPP_Default_Config="()"))
	static void MigrateLegacyOptionsToBlueprint(UBlueprint* Blueprint, const UPlaylistUserOptions* OptionsAsset, const TMap<FName, FName> OptionToPropertyNameOverrides, const FUserOptionMigrateLegacyDataConfig Config);
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="UserOptions|MigrateLegacyData", meta=(CPP_Default_OptionFilter="None", CPP_Default_OptionToPropertyNameOverride="None", CPP_Default_Config="()"))
	static void MigrateLegacyOptionToBlueprint(UBlueprint* Blueprint, const UPlaylistUserOptionBase* OptionAsset, const UPlaylistUserOptionsFilter* OptionFilter, const FName OptionToPropertyNameOverride, const FUserOptionMigrateLegacyDataConfig Config);
#endif

};

UCLASS(BlueprintType, Blueprintable, SparseClassDataType=UserOptionDefinitionContainer)
class UUserOptionDefinitionTestComponent : public UActorComponent
{
	GENERATED_BODY()

};

UCLASS(Transient)
class UUserOptionListProxy : public UObject, public IUserOptionDefinitionContainerInterface
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UPlaylistUserOptions> OptionsList;

};

