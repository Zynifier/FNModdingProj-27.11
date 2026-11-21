// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortniteEditorLibrary.h"

void UFortniteEditorLibrary::AddTag(FGameplayTagContainer& Container, const FGameplayTag& GameplayTag)
{
}

int32 UFortniteEditorLibrary::CalculateEditorOnlyPropertiesSize(const FString& ClassPath)
{
	return int32();
}

void UFortniteEditorLibrary::ChangeTargetSkeleton(UAnimBlueprint* AnimBlueprint, USkeleton* TargetSkeleton)
{
}

FClassPropertyReportData UFortniteEditorLibrary::CreateClassPropertyReport(const FString& BaseClassPath, const FClassPropertyReportConfig Config, bool& bValid)
{
	return FClassPropertyReportData();
}

FClassSizeReportData UFortniteEditorLibrary::CreateClassSizeReport(const FString& BaseClassPath, const FClassSizeReportConfig Config, bool& bValid)
{
	return FClassSizeReportData();
}

UAnimBlueprint* UFortniteEditorLibrary::CreateNewAnimBlueprint(USkeletalMesh* SkeletalMesh)
{
	return nullptr;
}

USkeletalMeshSocket* UFortniteEditorLibrary::CreateSocket(USkeleton* Skeleton, FName JointParent, FTransform Offset, FName SocketName)
{
	return nullptr;
}

bool UFortniteEditorLibrary::DuplicateAndRetarget(UAnimBlueprint* AnimBlueprint, USkeleton* NewSkeleton, UObject*& NewAnimBlueprint, TArray<UObject*>& DuplicatedAssets, bool bRetargetReferredAssets, bool bConvertSpace)
{
	return false;
}

UClass* UFortniteEditorLibrary::GeneratedClass(UBlueprint* BlueprintObj)
{
	return nullptr;
}

TMap<FString, FString> UFortniteEditorLibrary::GetAllPluginDependantRootCatalogOffersAndFulfillments()
{
	return TMap<FString, FString>();
}

UClass* UFortniteEditorLibrary::GetAnimBlueprintGeneratedClass(UAnimBlueprint* AnimBlueprint)
{
	return nullptr;
}

const UObject* UFortniteEditorLibrary::GetClassDefaultObject(const UClass* Class)
{
	return nullptr;
}

const UObject* UFortniteEditorLibrary::GetClassDefaultObjectFromPath(const FString& ClassAssetPath)
{
	return nullptr;
}

void UFortniteEditorLibrary::MovePluginDependantOffersAndFulfillmentsToPlugins(TMap<FString, FString> PluginDependencies)
{
}

void UFortniteEditorLibrary::OutputClassPropertyReport(const FClassPropertyReportData& InData)
{
}

void UFortniteEditorLibrary::OutputClassSizeReport(const FClassSizeReportData& InData)
{
}

UClass* UFortniteEditorLibrary::ParentClass(UBlueprint* BlueprintObj)
{
	return nullptr;
}

bool UFortniteEditorLibrary::Reparent(UBlueprint* BlueprintObj, UClass* NewParentClass, bool bForce)
{
	return false;
}

bool UFortniteEditorLibrary::RequestGameplayTag(FGameplayTag& OutTag, const FString& TagName, bool bErrorIfNotFound)
{
	return false;
}

FGameplayTagContainer UFortniteEditorLibrary::RequestGameplayTagChildren(const FGameplayTag& Parent)
{
	return FGameplayTagContainer();
}

bool UFortniteEditorLibrary::RunCustomFilterForFindClassUsages(const UObject* Object)
{
	return false;
}

void UFortniteEditorLibrary::SetDeveloperSettingPlaylist(const TSoftObjectPtr<UFortPlaylistAthena> Playlist)
{
}

void UFortniteEditorLibrary::SetDeveloperSettingPlaylistConditionalFlags(const TArray<FString> PlaylistConditionalFlags)
{
}

void UFortniteEditorLibrary::SetDeveloperSettingPlaylistOptions(const TMap<FString, FString> PlaylistOptions)
{
}

void UFortniteEditorLibrary::SetPreviewMesh(UAnimBlueprint* AnimBlueprint, USkeletalMesh* TargetPreviewSkeletalMesh)
{
}

void UFortniteEditorLibrary::SortStringArray(const TArray<FString>& InStrings, TArray<FString>& OutSortedStrings)
{
}

void UFortniteEditorLibrary::UpdateClassPropertyReport(FClassPropertyReportData& InData, const FString& AssetPath)
{
}

void UFortniteEditorLibrary::UpdateClassSizeReport(FClassSizeReportData& InData, const FString& AssetPath)
{
}
