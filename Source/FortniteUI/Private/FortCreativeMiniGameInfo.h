// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Layout/Margin.h"
#include "Types/SlateEnums.h"
#include "Creative/FortCreativeTypes.h"
#include "FortCreativeMiniGameInfo.generated.h"

class AFortVolume;
class UCommonTextBlock;
class UDynamicEntryBox;
class UInputComponent;
enum class ECreativePublishedIslandCodeDisplay : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSupportCreator);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnToggleDetails);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeMiniGameInfo : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortCreativeMiniGameInfo(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	bool ForceRefresh(bool bSetupInputComponent = true);

	UFUNCTION(BlueprintPure)
	void GetCreatorInformation(FString& OutCreatorName, FString& OutSupportCode) const;

protected:
	UFUNCTION(BlueprintPure, Category="Island Panel")
	bool AreDetailsToggleable() const;

	UFUNCTION(BlueprintPure)
	void GetIslandDescriptionLocationData(FMargin& Margin, TEnumAsByte<EHorizontalAlignment>& Alignment);

	UFUNCTION(BlueprintPure)
	TArray<FCreativeIslandDescriptionTag> GetIslandDescriptionTags() const;

	UFUNCTION(BlueprintPure, Category="Island Panel")
	bool IsStartGameEnabled() const;

	UFUNCTION(BlueprintNativeEvent)
	void OnCreatorNameChanged(const FText& CreatorName);

	UFUNCTION(BlueprintNativeEvent)
	void OnGameInfoBulletsChanged(const TArray<FString>& GameInfoBullets);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIslandCodeChanged(const FText& SupportCode);

	UFUNCTION(BlueprintNativeEvent)
	void OnIslandTitleChanged(const FText& IslandName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMiniGameStartedFromInputComponent();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPublishedIslandCodeDisplayChanged(const ECreativePublishedIslandCodeDisplay PublishedIslandCodeDisplay);

	UFUNCTION(BlueprintNativeEvent)
	void OnSupportCodeChanged(const FText& SupportCode);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTextSet();

	UFUNCTION(BlueprintCallable)
	void OnVisible();

	UFUNCTION(BlueprintCallable, Category="Island Panel")
	void PopPanelInputComponent();

	UFUNCTION(BlueprintCallable, Category="Island Panel")
	void PushPanelInputComponent();

	UPROPERTY(BlueprintAssignable, Category="Island Panel")
	FOnSupportCreator OnSupportCreator;

	UPROPERTY(BlueprintAssignable, Category="Island Panel")
	FOnToggleDetails OnToggleDetails;

private:
	UFUNCTION()
	void HandleCreativePlotLinkedVolumeChanged(AFortVolume* CreativeLinkedVolume);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMiniGameInfo", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Name;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMiniGameInfo", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CreatorName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMiniGameInfo", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SupportCode;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMiniGameInfo", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Bullet1;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMiniGameInfo", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Bullet2;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMiniGameInfo", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Bullet3;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMiniGameInfo", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true", EntryClass="ActivityBrowserTag"))
	TObjectPtr<UDynamicEntryBox> EntryBox_MiniGameTags;

	UPROPERTY(EditAnywhere, Category="Appearance")
	int32 SizeFont_Bullet_Mobile;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> PanelInputComponent;

};

