// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/AssetData.h"
#include "EditorUtilityWidget.h"
#include "Engine/DataAsset.h"
#include "UObject/NoExportTypes.h"
#include "FortAssetDataUtilityTool.generated.h"

class UFortAssetDataUtilityTool;
class UFortAssetDataUtilityToolAction;
class UFortAssetDataUtilityToolArrayModifier;
class UFortAssetDataUtilityToolFilter;
class UFortAssetDataUtilityToolGatherer;

UENUM(BlueprintType)
enum class EAssetDataUtilityToolFilterResult : uint8
{
	/** AssetData should not pass the filter */
	AssetFail = 0,
	/** AssetData should pass the filter */
	AssetPass = 1,
};

UCLASS(BlueprintType)
class UFortAssetDataUtilityTool : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	bool RunActionsOnAssets(const TArray<FAssetData>& AssetsToRunActions) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	TArray<FAssetData> RunFiltersAndPostFilterModifiers(const TArray<FAssetData>& AssetsToFilter) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	TArray<FAssetData> RunFiltersOnAssets(const TArray<FAssetData>& AssetsToFilter) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	TArray<FAssetData> RunGatherers() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	TArray<FAssetData> RunGatherersAndPostGatherModifiers() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void RunPostFilterModifiers(UPARAM(ref) TArray<FAssetData>& InOutArrayToModify) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void RunPostGatherModifiers(UPARAM(ref) TArray<FAssetData>& InOutArrayToModify) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, meta=(CallInEditor="true"))
	void RunTool() const;

	UPROPERTY(EditAnywhere, Instanced, Category="FortAssetDataUtilityTool")
	TArray<TObjectPtr<UFortAssetDataUtilityToolGatherer>> Gatherers;

	UPROPERTY(EditAnywhere, Instanced, Category="FortAssetDataUtilityTool")
	TArray<TObjectPtr<UFortAssetDataUtilityToolArrayModifier>> PostGatherModifiers;

	UPROPERTY(EditAnywhere, Instanced, Category="FortAssetDataUtilityTool")
	TArray<TObjectPtr<UFortAssetDataUtilityToolFilter>> Filters;

	UPROPERTY(EditAnywhere, Instanced, Category="FortAssetDataUtilityTool")
	TArray<TObjectPtr<UFortAssetDataUtilityToolArrayModifier>> PostFilterModifiers;

	UPROPERTY(EditAnywhere, Instanced, Category="FortAssetDataUtilityTool")
	TArray<TObjectPtr<UFortAssetDataUtilityToolAction>> Actions;

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew, MinimalAPI, BlueprintType, Blueprintable)
class UFortAssetDataUtilityToolAction : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool RunActionOnAssetDataArray(const TArray<FAssetData>& AssetDataArray) const;

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew, MinimalAPI, BlueprintType, Blueprintable)
class UFortAssetDataUtilityToolArrayModifier : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RunArrayModifier(UPARAM(ref) TArray<FAssetData>& InOutAssetDataArray) const;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAssetDataUtilityToolEditorWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void MakeTempToolAssetDataToModify();

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void RunActionsOnAssets(const TArray<FAssetData>& AssetsToRunActions) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	TArray<FAssetData> RunFiltersOnAssets(const TArray<FAssetData>& AssetsToFilter) const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortAssetDataUtilityToolEditorWidget")
	TObjectPtr<UFortAssetDataUtilityTool> ToolAssetDataToModify;

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew, MinimalAPI, BlueprintType, Blueprintable)
class UFortAssetDataUtilityToolFilter : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool AssetDataPassesFilter(const FAssetData& AssetData) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void CleanupFilterData();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void InitializeFilterData();

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew, MinimalAPI, BlueprintType, Blueprintable)
class UFortAssetDataUtilityToolGatherer : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	TArray<FAssetData> RunGatherer() const;

};

