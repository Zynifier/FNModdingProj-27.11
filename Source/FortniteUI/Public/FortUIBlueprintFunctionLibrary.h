// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetTextLibrary.h"
#include "Math/MathFwd.h"
#include "Misc/Timespan.h"
#include "Styling/SlateBrush.h"
#include "Context/FortStoreContext.h"
#include "FortBrushSize.h"
#include "FortDialogTypes.h"
#include "FortMultiSize.h"
#include "FortUIBlueprintFunctionLibrary.generated.h"

class AActor;
class AFortPlayerController;
class APlayerController;
class UCommonActivatablePanelLegacy;
class UCommonActivatableWidget;
class UFortGiftBoxItem;
class UFortItem;
class UFortItemDefinition;
class UFortQuestItem;
class UImage;
class UObject;
class USocialUser;
class UTexture2D;
class UTextureRenderTarget2D;
class UUserWidget;
class UWidget;
enum class EActivatePanelOption : uint8;
enum class EFortErrorSeverity : uint8;
enum class EFortUIFeature : uint8;

UENUM(BlueprintType)
enum class EActivatePanelOption : uint8
{
	Show = 0,
	Hide = 1,
	PlatformDefault = 2,
};

UCLASS(MinimalAPI)
class UFortUIBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnTabChangedBP, const EFortUIFeature, LeavingFeature, const EFortUIFeature, EnteringFeature);

public:
	UFUNCTION(BlueprintPure, Category="Fort UI Management")
	static bool AreModalsActive(AFortPlayerController* LocalPlayerController);

	UFUNCTION(BlueprintPure, Category="Fort UI Management")
	static bool AreModalsConfirmationsErrorsActive(AFortPlayerController* LocalPlayerController);

	UFUNCTION(BlueprintCallable)
	static bool AreParentalControlsEnabled(const UUserWidget* Context);

	UFUNCTION(BlueprintCallable)
	static void BindToTabChange(UWidget* Context, const FOnTabChangedBP& EventToBind);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static bool CanNavigateToQuestObjective(UFortQuestItem* QuestItem);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void CenterWidget(UUserWidget* Context, UWidget* ToCenter);

	UFUNCTION(BlueprintCallable, Category="Rendering")
	static void DrawWidgetToRenderTarget(UUserWidget* Widget, UTextureRenderTarget2D* RenderTarget);

	UFUNCTION(BlueprintCallable, Category="Fort Dialogs", meta=(WorldContext="WorldContextObject"))
	static void EndWaitForConfirmationDialog(UObject* WorldContextObject, UPARAM(ref) FFortDialogExternalLatentActionHandle& Handle);

	UFUNCTION(BlueprintPure, Category="Fort Dialogs", meta=(CompactNodeTitle="==", DisplayName="Equal (FFortDialogExternalLatentActionHandle)", Keywords="== equal"))
	static bool EqualEqual_FFortDialogWaitingForLatentActionHandle(const FFortDialogExternalLatentActionHandle& A, const FFortDialogExternalLatentActionHandle& B);

	UFUNCTION(BlueprintPure, Category="Asset Management")
	static UObject* GetAssetFromTemplateId(const FString& TemplateId);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static UUserWidget* GetCachedWidget(UUserWidget* Context, UClass* WidgetClass);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management")
	static UUserWidget* GetCachedWidgetForPlayer(AFortPlayerController* LocalPlayerController, UClass* WidgetClass);

	UFUNCTION(BlueprintCallable, Category="Display Helper")
	static TArray<UImage*> GetContainedImages(UWidget* InWidget);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static UCommonActivatablePanelLegacy* GetCurrentModal(UUserWidget* Context);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management")
	static UCommonActivatableWidget* GetCurrentStateWidget(APlayerController* PlayerController);

	UFUNCTION(BlueprintPure, Category="Display Helper")
	static const FText& GetInfinitySymbolText();

	UFUNCTION(BlueprintPure, Category="Item Preview Image")
	static FSlateBrush GetItemDefinitionSmallPreviewImageBrush(const UFortItemDefinition* ItemDefinition, EFortBrushSize::Type BrushSize);

	UFUNCTION(BlueprintPure, Category="Item Preview Image")
	static FFortMultiSizeBrush GetItemDefinitionSmallPreviewImageMultiSizeBrush(const UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintPure, Category="Item Preview Image")
	static FSlateBrush GetItemSmallPreviewImageBrush(const UFortItem* Item, EFortBrushSize::Type BrushSize);

	UFUNCTION(BlueprintPure, Category="Item Preview Image")
	static FFortMultiSizeBrush GetItemSmallPreviewImageMultiSizeBrush(const UFortItem* Item);

	UFUNCTION(BlueprintPure, Category="CardPackOffer")
	static bool GetMetaBoolOnOffer(const FCardPackOffer& Offer, const FString& Key, bool bDefaultValue = false);

	UFUNCTION(BlueprintPure, Category="CardPackOffer")
	static int32 GetMetaIntOnOffer(const FCardPackOffer& Offer, const FString& Key, int32 DefaultValue = 0);

	UFUNCTION(BlueprintPure, Category="CardPackOffer")
	static FString GetMetaStringOnOffer(const FCardPackOffer& Offer, const FString& Key);

	UFUNCTION(BlueprintPure, Category="Item Preview Image")
	static UTexture2D* GetOrLoadSynchronously(const TSoftObjectPtr<UTexture2D>& SoftTexture2D);

	UFUNCTION(BlueprintPure, Category="Inventory")
	static FText GetShorthandQuantity(const int32 Quantity, const int32 MinimumFractionalDigits = 0, const int32 MaximumFractionalDigits = 2, const bool bShouldRoundDown = false);

	UFUNCTION(BlueprintPure, Category="Display Helper")
	static FText GetShorthandQuantityWithLimitedDigits(const int32 Score, int32 MaxDigits = 3);

	UFUNCTION(BlueprintPure, Category="Item Preview Image")
	static FVector2D GetStandardBrushSize(EFortBrushSize::Type BrushSize);

	UFUNCTION(BlueprintPure, Category="Display Helper")
	static FText GetTimespanAsSimpleString(FTimespan Timespan);

	UFUNCTION(BlueprintCallable, Category="Fort Dialogs")
	static void InvalidateLatentActionHandle(UPARAM(ref) FFortDialogExternalLatentActionHandle& Handle);

	UFUNCTION(BlueprintCallable)
	static bool IsCabinModeEnabled(const UUserWidget* Context);

	UFUNCTION(BlueprintPure, Category="Fort UI State")
	static bool IsContentOnStack(AFortPlayerController* LocalPlayerController);

	UFUNCTION(BlueprintPure, Category="Fort Dialogs")
	static bool IsLatentActionHandleValid(const FFortDialogExternalLatentActionHandle& Handle);

	UFUNCTION(BlueprintPure, Category="Fort UI Management", meta=(DisplayName="Is UI Added to Viewport"))
	static bool IsUIAddedToViewport(AFortPlayerController* LocalPlayerController);

	UFUNCTION(BlueprintPure, Category="Fort UI Management")
	static bool IsUIInputAllowed(APlayerController* LocalPlayerController);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void KillConfirmation(UUserWidget* Context);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void NavigateForGift(UUserWidget* Context, UFortGiftBoxItem* Item);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void NavigateToFeature(UUserWidget* Context, EFortUIFeature Feature, bool bClearPrimaryContentStack);

	UFUNCTION(BlueprintCallable)
	static void NavigateToQuestScreen(UWidget* Context, const FGameplayTag& StartingCategoryTag);

	UFUNCTION(BlueprintPure, Category="Fort Dialogs", meta=(CompactNodeTitle="!=", DisplayName="NotEqual (FFortDialogExternalLatentActionHandle)", Keywords="!= not equal"))
	static bool NotEqual_FFortDialogWaitingForLatentActionHandle(const FFortDialogExternalLatentActionHandle& A, const FFortDialogExternalLatentActionHandle& B);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void PopActivatablePanel(UUserWidget* Context, UCommonActivatablePanelLegacy* Panel);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void PopActivatablePanelInModalLayer(UUserWidget* Context, UCommonActivatablePanelLegacy* Panel);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void PopAllContentWidgets(UUserWidget* Context);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void PopContentWidget(UUserWidget* Context);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management")
	static void PopContentWidgetForPlayer(AFortPlayerController* LocalPlayerController);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void PopCurrentModal(UUserWidget* Context);

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Viewport")
	static bool ProjectToWidgetPosition(APlayerController* PlayerController, FVector WorldLocation, FVector2D& ScreenPosition, bool bPlayerViewportRelative);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void PushActivatablePanel(UUserWidget* Context, UCommonActivatablePanelLegacy* Panel);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void PushContentWidget(UUserWidget* Context, UWidget* PushWidget);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void PushContentWidgetAdvanced(UUserWidget* Context, UWidget* PushWidget, bool bHideHeader, bool bHideFooter, bool bHideChatWidget);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management")
	static void PushContentWidgetAdvancedForPlayer(AFortPlayerController* LocalPlayerController, UWidget* PushWidget, bool bHideHeader, bool bHideFooter, bool bHideChatWidget);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management")
	static void PushContentWidgetForPlayer(AFortPlayerController* LocalPlayerController, UWidget* PushWidget);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void RegisterActiveCinematic(UObject* Context);

	UFUNCTION(BlueprintCallable, Category="Display Helper", meta=(DefaultToSelf="Context", HidePin="Context"))
	static void RequestToOpenParentalControls(UUserWidget* Context);

	UFUNCTION(BlueprintCallable, Category="Display Helper")
	static void RequestToOpenPlayerFeedbackModal(UUserWidget* Context, USocialUser* UserToReport = nullptr);

	UFUNCTION(BlueprintCallable, Category="Display Helper")
	static void RequestToOpenPlayerFeedbackModalWithReportOrigin(UUserWidget* Context, const FString& ReportOrigin);

	UFUNCTION(BlueprintCallable, Category="Display Helper")
	static void RequestToOpenSpecificPlayerFeedbackModal(UUserWidget* Context, USocialUser* UserToReport, const TMap<FString, FString>& InAnalyticsContext);

	UFUNCTION(BlueprintCallable, Category="Settings")
	static void ResetKeyboardMousePlayerBindingsToPreset(AFortPlayerController* LocalPlayerController, int32 PresetToSet);

	UFUNCTION(BlueprintPure, Category="Display Helper")
	static float RoundFloat(float Value, ERoundingMode RoundingMode);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Input", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void SetInputAllowedForAllLocalPlayers(const UObject* WorldContextObject, const bool bEnabled, const FName& Reason);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Input")
	static void SetInputAllowedForPlayer(const bool bEnabled, const FName& Reason, AFortPlayerController* FortPC);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void SetScrollWidget(UUserWidget* Context, UWidget* ToScroll);

	UFUNCTION(BlueprintCallable, Category="Display Helper", meta=(WorldContext="Context"))
	static void SetWidgetCZonesAutomation(UUserWidget* Context, bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void ShowErrorDialog(UUserWidget* Context, FText DisplayMessage, const FString& ErrorCode, EFortErrorSeverity ErrorSeverity);

	UFUNCTION(BlueprintCallable, Category="Cooking Non-Determinism")
	static void SortActorArray(const TArray<AActor*>& InActors, TArray<AActor*>& OutSortedActors);

	UFUNCTION(BlueprintPure)
	static FString ToOrdinal(int32 Number);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void TryPopActivatablePanel(UUserWidget* Context, UCommonActivatablePanelLegacy* Panel);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void TryPushWidgetAsActivatablePanel(UUserWidget* Context, UUserWidget* PushWidget, EActivatePanelOption Header = EActivatePanelOption::PlatformDefault, EActivatePanelOption Footer = EActivatePanelOption::PlatformDefault, EActivatePanelOption ChatWidget = EActivatePanelOption::PlatformDefault);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management")
	static void TryPushWidgetAsActivatablePanelForPlayer(APlayerController* OwningPlayer, UUserWidget* PushWidget, EActivatePanelOption Header = EActivatePanelOption::PlatformDefault, EActivatePanelOption Footer = EActivatePanelOption::PlatformDefault, EActivatePanelOption ChatWidget = EActivatePanelOption::PlatformDefault);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void TryPushWidgetAsModalPanel(UUserWidget* Context, UUserWidget* PushWidget);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management")
	static void TryPushWidgetAsModalPanelForPlayer(AFortPlayerController* LocalPlayerController, UUserWidget* PushWidget);

	UFUNCTION(BlueprintCallable, Category="Fort UI Management", meta=(WorldContext="Context"))
	static void UnregisterActiveCinematic(UObject* Context);

};

