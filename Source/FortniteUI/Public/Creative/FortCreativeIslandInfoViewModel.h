// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Creative/FortCreativeLoadedLinkData.h"
#include "Creative/FortCreativeTypes.h"
#include "DynamicXp/FortDynamicXpCalculatorData.h"
#include "FortCreativeIslandInfoViewModel.generated.h"

class UTexture2D;
class UTexture2DDynamic;

UCLASS(BlueprintType, meta=(MVVMAllowedContextCreationType="Manual"))
class UFortCreativeIslandInfoViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFailedToUpdateCreativePlotData, const FCreativeIslandInfo&, IslandInfo);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIslandMetaDataUpdateComplete, FString, Error);

public:
	UFUNCTION(BlueprintPure)
	FText GetIslandCode() const;

	UFUNCTION(BlueprintPure)
	TArray<FCreativeIslandDescriptionTag> GetIslandDescriptionTags() const;

	UFUNCTION(BlueprintPure)
	FText GetIslandTitle() const;

	UFUNCTION(BlueprintCallable)
	void InitializeViewModel();

	UFUNCTION(BlueprintPure)
	bool IsPlayerInAnExperienceTheyOwn() const;

	UFUNCTION(BlueprintCallable)
	void SetIslandDescriptionTags(const TArray<FCreativeIslandDescriptionTag>& IslandDescriptionTags);

	UFUNCTION(BlueprintCallable)
	void UnbindViewModel();

	UFUNCTION(BlueprintCallable)
	void UpdateCreativePlotData(const FString& NewIslandTitle, const TArray<FString>& NewIslandIntroductions);

	UPROPERTY(BlueprintAssignable)
	FOnIslandMetaDataUpdateComplete OnIslandMetaDataUpdateComplete;

	UPROPERTY(BlueprintAssignable)
	FOnFailedToUpdateCreativePlotData OnFailedToUpdateCreativePlotData;

private:
	UFUNCTION()
	void HandleDownloadThumbnailComplete(const bool bSuccess, UTexture2DDynamic* InThumbnailTexture);

	UFUNCTION()
	void HandleIslandMetaDataUpdateComplete(const FString& Error);

	UFUNCTION()
	void HandleLinkDataQueryComplete(const bool bSuccess, const FString& ErrorMessage, const FCreativeLoadedLinkData& LinkData);

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandInfoViewModel", meta=(AllowPrivateAccess))
	TArray<FText> IslandIntroduction;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandInfoViewModel", meta=(AllowPrivateAccess))
	EDynamicXpCalibrationPhase XpCalibrationPhase;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandInfoViewModel", meta=(AllowPrivateAccess))
	TObjectPtr<UTexture2DDynamic> ThumbnailTexture;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandInfoViewModel", meta=(AllowPrivateAccess))
	TObjectPtr<UTexture2D> LobbyBackgroundTexture;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandInfoViewModel", meta=(AllowPrivateAccess))
	FString PublishedCreatorName;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeIslandInfoViewModel", meta=(AllowPrivateAccess))
	bool bIsUpdatingIslandMetaData;

};

