// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "FortniteEditorLibrary.generated.h"

class UAnimBlueprint;
class UBlueprint;
class UFortPlaylistAthena;
class UObject;
class USkeletalMesh;
class USkeletalMeshSocket;
class USkeleton;

USTRUCT(BlueprintType)
struct FClassPropertyReportConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClassPropertyReportConfig")
	bool bCheckTimesDefaultChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClassPropertyReportConfig")
	bool bOnlyIncludeEditable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClassPropertyReportConfig")
	bool bIncludeInstanceEditable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClassPropertyReportConfig")
	bool bIncludeBPModifiable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClassPropertyReportConfig")
	bool bIncludeExposedInSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClassPropertyReportConfig")
	TArray<FString> VerboseLoggedChangedProperties;

	UPROPERTY()
	FString SaveFileName;

};

USTRUCT(BlueprintType)
struct FClassPropertyReportData
{
	GENERATED_BODY()

};

USTRUCT()
struct FClassPropertyReportDataEntry
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FClassSizeReportConfig
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString SaveFileName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClassSizeReportConfig")
	int32 EditorSizeOffset;

};

USTRUCT(BlueprintType)
struct FClassSizeReportData
{
	GENERATED_BODY()

};

USTRUCT()
struct FClassSizeReportDataEntry
{
	GENERATED_BODY()

};

UCLASS()
class FORTNITEEDITOR_API UFortniteEditorLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(ScriptMethod))
	static void AddTag(UPARAM(ref) FGameplayTagContainer& Container, const FGameplayTag& GameplayTag);

	UFUNCTION(BlueprintCallable)
	static int32 CalculateEditorOnlyPropertiesSize(const FString& ClassPath);

	UFUNCTION(BlueprintCallable, meta=(ScriptMethod))
	static void ChangeTargetSkeleton(UAnimBlueprint* AnimBlueprint, USkeleton* TargetSkeleton);

	UFUNCTION(BlueprintCallable)
	static FClassPropertyReportData CreateClassPropertyReport(const FString& BaseClassPath, const FClassPropertyReportConfig Config, bool& bValid);

	UFUNCTION(BlueprintCallable)
	static FClassSizeReportData CreateClassSizeReport(const FString& BaseClassPath, const FClassSizeReportConfig Config, bool& bValid);

	UFUNCTION(BlueprintCallable, meta=(ScriptMethod))
	static UAnimBlueprint* CreateNewAnimBlueprint(USkeletalMesh* SkeletalMesh);

	UFUNCTION(BlueprintCallable, meta=(ScriptMethod))
	static USkeletalMeshSocket* CreateSocket(USkeleton* Skeleton, FName JointParent, FTransform Offset, FName SocketName = FName(TEXT("")));

	UFUNCTION(BlueprintCallable, meta=(ScriptMethod))
	static bool DuplicateAndRetarget(UAnimBlueprint* AnimBlueprint, USkeleton* NewSkeleton, UObject*& NewAnimBlueprint, TArray<UObject*>& DuplicatedAssets, bool bRetargetReferredAssets = true, bool bConvertSpace = true);

	UFUNCTION(BlueprintCallable)
	static UClass* GeneratedClass(UBlueprint* BlueprintObj);

	UFUNCTION(BlueprintCallable)
	static TMap<FString, FString> GetAllPluginDependantRootCatalogOffersAndFulfillments();

	UFUNCTION(BlueprintCallable, meta=(ScriptMethod))
	static UClass* GetAnimBlueprintGeneratedClass(UAnimBlueprint* AnimBlueprint);

	UFUNCTION(BlueprintCallable)
	static const UObject* GetClassDefaultObject(const UClass* Class);

	UFUNCTION(BlueprintCallable)
	static const UObject* GetClassDefaultObjectFromPath(const FString& ClassAssetPath);

	UFUNCTION(BlueprintCallable)
	static void MovePluginDependantOffersAndFulfillmentsToPlugins(TMap<FString, FString> PluginDependencies);

	UFUNCTION(BlueprintCallable)
	static void OutputClassPropertyReport(const FClassPropertyReportData& InData);

	UFUNCTION(BlueprintCallable)
	static void OutputClassSizeReport(const FClassSizeReportData& InData);

	UFUNCTION(BlueprintCallable, meta=(ScriptMethod))
	static UClass* ParentClass(UBlueprint* BlueprintObj);

	UFUNCTION(BlueprintCallable, meta=(ScriptMethod))
	static bool Reparent(UBlueprint* BlueprintObj, UClass* NewParentClass, bool bForce = false);

	UFUNCTION(BlueprintCallable)
	static bool RequestGameplayTag(FGameplayTag& OutTag, const FString& TagName, bool bErrorIfNotFound = false);

	UFUNCTION(BlueprintCallable, meta=(ScriptMethod))
	static FGameplayTagContainer RequestGameplayTagChildren(const FGameplayTag& Parent);

	UFUNCTION(BlueprintCallable)
	static bool RunCustomFilterForFindClassUsages(const UObject* Object);

	UFUNCTION(BlueprintCallable)
	static void SetDeveloperSettingPlaylist(const TSoftObjectPtr<UFortPlaylistAthena> Playlist);

	UFUNCTION(BlueprintCallable)
	static void SetDeveloperSettingPlaylistConditionalFlags(const TArray<FString> PlaylistConditionalFlags);

	UFUNCTION(BlueprintCallable)
	static void SetDeveloperSettingPlaylistOptions(const TMap<FString, FString> PlaylistOptions);

	UFUNCTION(BlueprintCallable, meta=(ScriptMethod))
	static void SetPreviewMesh(UAnimBlueprint* AnimBlueprint, USkeletalMesh* TargetPreviewSkeletalMesh);

	UFUNCTION(BlueprintCallable)
	static void SortStringArray(const TArray<FString>& InStrings, TArray<FString>& OutSortedStrings);

	UFUNCTION(BlueprintCallable)
	static void UpdateClassPropertyReport(UPARAM(ref) FClassPropertyReportData& InData, const FString& AssetPath);

	UFUNCTION(BlueprintCallable)
	static void UpdateClassSizeReport(UPARAM(ref) FClassSizeReportData& InData, const FString& AssetPath);

};

