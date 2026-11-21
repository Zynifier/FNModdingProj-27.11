// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "FortUITypes.h"
#include "FortUpgradeInfo.generated.h"

class UFortHomebaseNodeItemDefinition;
class UMediaSource;
class UTexture2D;
enum class EUpgradeInfoImageSize : uint8;

UENUM(BlueprintType)
enum class EUpgradeInfoImageSize : uint8
{
	Small = 0,
	Large = 1,
};

USTRUCT(BlueprintType)
struct FHomebaseNodeDisplayData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HomebaseNodeDisplayData")
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HomebaseNodeDisplayData", meta=(multiline="TRUE"))
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HomebaseNodeDisplayData")
	TSoftObjectPtr<UTexture2D> LargePreviewImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HomebaseNodeDisplayData")
	TSoftObjectPtr<UTexture2D> SmallPreviewImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HomebaseNodeDisplayData")
	TObjectPtr<UMediaSource> PreviewVideoMediaSource;

};

UCLASS(BlueprintType)
class UFortUpgradeInfo : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortUpgradeInfo")
	void BackwardPreview();

	UFUNCTION(BlueprintPure, Category="FortUpgrdaeInfo")
	bool CanAffordUpgrade() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	bool CanPreview() const;

	UFUNCTION(BlueprintCallable, Category="FortUpgradeInfo")
	void ForwardPreview();

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	int32 GetCost() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	int32 GetCurrentLevel() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	FText GetDescription() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	bool GetDisplayAttributes(TArray<FFortDisplayAttribute>& OutDisplayAttributes) const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	TSoftObjectPtr<UTexture2D> GetIcon(EUpgradeInfoImageSize ImageSize) const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	FText GetItemName() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	int32 GetMaxLevel() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	int32 GetNextLevel() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	FText GetNextLevelDescription() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	FText GetNextLevelTitle() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	FText GetTitle() const;

	UFUNCTION(BlueprintPure, Category="FortUpgrdaeInfo")
	int32 GetUpgradeUnlockLevel() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	UMediaSource* GetVideo() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	bool IsPreviewing() const;

	UFUNCTION(BlueprintPure, Category="FortUpgradeInfo")
	bool IsUpgradeUnlocked() const;

private:
	UPROPERTY()
	TObjectPtr<UFortHomebaseNodeItemDefinition> NodeItemDef;

};

