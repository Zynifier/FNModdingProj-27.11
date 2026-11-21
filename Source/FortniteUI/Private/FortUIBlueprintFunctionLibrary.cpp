// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortUIBlueprintFunctionLibrary.h"

bool UFortUIBlueprintFunctionLibrary::AreModalsActive(AFortPlayerController* LocalPlayerController)
{
	return false;
}

bool UFortUIBlueprintFunctionLibrary::AreModalsConfirmationsErrorsActive(AFortPlayerController* LocalPlayerController)
{
	return false;
}

bool UFortUIBlueprintFunctionLibrary::AreParentalControlsEnabled(const UUserWidget* Context)
{
	return false;
}

void UFortUIBlueprintFunctionLibrary::BindToTabChange(UWidget* Context, const FOnTabChangedBP& EventToBind)
{
}

bool UFortUIBlueprintFunctionLibrary::CanNavigateToQuestObjective(UFortQuestItem* QuestItem)
{
	return false;
}

void UFortUIBlueprintFunctionLibrary::CenterWidget(UUserWidget* Context, UWidget* ToCenter)
{
}

void UFortUIBlueprintFunctionLibrary::DrawWidgetToRenderTarget(UUserWidget* Widget, UTextureRenderTarget2D* RenderTarget)
{
}

void UFortUIBlueprintFunctionLibrary::EndWaitForConfirmationDialog(UObject* WorldContextObject, FFortDialogExternalLatentActionHandle& Handle)
{
}

bool UFortUIBlueprintFunctionLibrary::EqualEqual_FFortDialogWaitingForLatentActionHandle(const FFortDialogExternalLatentActionHandle& A, const FFortDialogExternalLatentActionHandle& B)
{
	return false;
}

UObject* UFortUIBlueprintFunctionLibrary::GetAssetFromTemplateId(const FString& TemplateId)
{
	return nullptr;
}

UUserWidget* UFortUIBlueprintFunctionLibrary::GetCachedWidget(UUserWidget* Context, UClass* WidgetClass)
{
	return nullptr;
}

UUserWidget* UFortUIBlueprintFunctionLibrary::GetCachedWidgetForPlayer(AFortPlayerController* LocalPlayerController, UClass* WidgetClass)
{
	return nullptr;
}

TArray<UImage*> UFortUIBlueprintFunctionLibrary::GetContainedImages(UWidget* InWidget)
{
	return TArray<UImage*>();
}

UCommonActivatablePanelLegacy* UFortUIBlueprintFunctionLibrary::GetCurrentModal(UUserWidget* Context)
{
	return nullptr;
}

UCommonActivatableWidget* UFortUIBlueprintFunctionLibrary::GetCurrentStateWidget(APlayerController* PlayerController)
{
	return nullptr;
}

const FText& UFortUIBlueprintFunctionLibrary::GetInfinitySymbolText()
{
	static FText Dummy;
	return Dummy;
}

FSlateBrush UFortUIBlueprintFunctionLibrary::GetItemDefinitionSmallPreviewImageBrush(const UFortItemDefinition* ItemDefinition, EFortBrushSize::Type BrushSize)
{
	return FSlateBrush();
}

FFortMultiSizeBrush UFortUIBlueprintFunctionLibrary::GetItemDefinitionSmallPreviewImageMultiSizeBrush(const UFortItemDefinition* ItemDefinition)
{
	return FFortMultiSizeBrush();
}

FSlateBrush UFortUIBlueprintFunctionLibrary::GetItemSmallPreviewImageBrush(const UFortItem* Item, EFortBrushSize::Type BrushSize)
{
	return FSlateBrush();
}

FFortMultiSizeBrush UFortUIBlueprintFunctionLibrary::GetItemSmallPreviewImageMultiSizeBrush(const UFortItem* Item)
{
	return FFortMultiSizeBrush();
}

bool UFortUIBlueprintFunctionLibrary::GetMetaBoolOnOffer(const FCardPackOffer& Offer, const FString& Key, bool bDefaultValue)
{
	return false;
}

int32 UFortUIBlueprintFunctionLibrary::GetMetaIntOnOffer(const FCardPackOffer& Offer, const FString& Key, int32 DefaultValue)
{
	return int32();
}

FString UFortUIBlueprintFunctionLibrary::GetMetaStringOnOffer(const FCardPackOffer& Offer, const FString& Key)
{
	return FString();
}

UTexture2D* UFortUIBlueprintFunctionLibrary::GetOrLoadSynchronously(const TSoftObjectPtr<UTexture2D>& SoftTexture2D)
{
	return nullptr;
}

FText UFortUIBlueprintFunctionLibrary::GetShorthandQuantity(const int32 Quantity, const int32 MinimumFractionalDigits, const int32 MaximumFractionalDigits, const bool bShouldRoundDown)
{
	return FText();
}

FText UFortUIBlueprintFunctionLibrary::GetShorthandQuantityWithLimitedDigits(const int32 Score, int32 MaxDigits)
{
	return FText();
}

FVector2D UFortUIBlueprintFunctionLibrary::GetStandardBrushSize(EFortBrushSize::Type BrushSize)
{
	return FVector2D();
}

FText UFortUIBlueprintFunctionLibrary::GetTimespanAsSimpleString(FTimespan Timespan)
{
	return FText();
}

void UFortUIBlueprintFunctionLibrary::InvalidateLatentActionHandle(FFortDialogExternalLatentActionHandle& Handle)
{
}

bool UFortUIBlueprintFunctionLibrary::IsCabinModeEnabled(const UUserWidget* Context)
{
	return false;
}

bool UFortUIBlueprintFunctionLibrary::IsContentOnStack(AFortPlayerController* LocalPlayerController)
{
	return false;
}

bool UFortUIBlueprintFunctionLibrary::IsLatentActionHandleValid(const FFortDialogExternalLatentActionHandle& Handle)
{
	return false;
}

bool UFortUIBlueprintFunctionLibrary::IsUIAddedToViewport(AFortPlayerController* LocalPlayerController)
{
	return false;
}

bool UFortUIBlueprintFunctionLibrary::IsUIInputAllowed(APlayerController* LocalPlayerController)
{
	return false;
}

void UFortUIBlueprintFunctionLibrary::KillConfirmation(UUserWidget* Context)
{
}

void UFortUIBlueprintFunctionLibrary::NavigateForGift(UUserWidget* Context, UFortGiftBoxItem* Item)
{
}

void UFortUIBlueprintFunctionLibrary::NavigateToFeature(UUserWidget* Context, EFortUIFeature Feature, bool bClearPrimaryContentStack)
{
}

void UFortUIBlueprintFunctionLibrary::NavigateToQuestScreen(UWidget* Context, const FGameplayTag& StartingCategoryTag)
{
}

bool UFortUIBlueprintFunctionLibrary::NotEqual_FFortDialogWaitingForLatentActionHandle(const FFortDialogExternalLatentActionHandle& A, const FFortDialogExternalLatentActionHandle& B)
{
	return false;
}

void UFortUIBlueprintFunctionLibrary::PopActivatablePanel(UUserWidget* Context, UCommonActivatablePanelLegacy* Panel)
{
}

void UFortUIBlueprintFunctionLibrary::PopActivatablePanelInModalLayer(UUserWidget* Context, UCommonActivatablePanelLegacy* Panel)
{
}

void UFortUIBlueprintFunctionLibrary::PopAllContentWidgets(UUserWidget* Context)
{
}

void UFortUIBlueprintFunctionLibrary::PopContentWidget(UUserWidget* Context)
{
}

void UFortUIBlueprintFunctionLibrary::PopContentWidgetForPlayer(AFortPlayerController* LocalPlayerController)
{
}

void UFortUIBlueprintFunctionLibrary::PopCurrentModal(UUserWidget* Context)
{
}

bool UFortUIBlueprintFunctionLibrary::ProjectToWidgetPosition(APlayerController* PlayerController, FVector WorldLocation, FVector2D& ScreenPosition, bool bPlayerViewportRelative)
{
	return false;
}

void UFortUIBlueprintFunctionLibrary::PushActivatablePanel(UUserWidget* Context, UCommonActivatablePanelLegacy* Panel)
{
}

void UFortUIBlueprintFunctionLibrary::PushContentWidget(UUserWidget* Context, UWidget* PushWidget)
{
}

void UFortUIBlueprintFunctionLibrary::PushContentWidgetAdvanced(UUserWidget* Context, UWidget* PushWidget, bool bHideHeader, bool bHideFooter, bool bHideChatWidget)
{
}

void UFortUIBlueprintFunctionLibrary::PushContentWidgetAdvancedForPlayer(AFortPlayerController* LocalPlayerController, UWidget* PushWidget, bool bHideHeader, bool bHideFooter, bool bHideChatWidget)
{
}

void UFortUIBlueprintFunctionLibrary::PushContentWidgetForPlayer(AFortPlayerController* LocalPlayerController, UWidget* PushWidget)
{
}

void UFortUIBlueprintFunctionLibrary::RegisterActiveCinematic(UObject* Context)
{
}

void UFortUIBlueprintFunctionLibrary::RequestToOpenParentalControls(UUserWidget* Context)
{
}

void UFortUIBlueprintFunctionLibrary::RequestToOpenPlayerFeedbackModal(UUserWidget* Context, USocialUser* UserToReport)
{
}

void UFortUIBlueprintFunctionLibrary::RequestToOpenPlayerFeedbackModalWithReportOrigin(UUserWidget* Context, const FString& ReportOrigin)
{
}

void UFortUIBlueprintFunctionLibrary::RequestToOpenSpecificPlayerFeedbackModal(UUserWidget* Context, USocialUser* UserToReport, const TMap<FString, FString>& InAnalyticsContext)
{
}

void UFortUIBlueprintFunctionLibrary::ResetKeyboardMousePlayerBindingsToPreset(AFortPlayerController* LocalPlayerController, int32 PresetToSet)
{
}

float UFortUIBlueprintFunctionLibrary::RoundFloat(float Value, ERoundingMode RoundingMode)
{
	return float();
}

void UFortUIBlueprintFunctionLibrary::SetInputAllowedForAllLocalPlayers(const UObject* WorldContextObject, const bool bEnabled, const FName& Reason)
{
}

void UFortUIBlueprintFunctionLibrary::SetInputAllowedForPlayer(const bool bEnabled, const FName& Reason, AFortPlayerController* FortPC)
{
}

void UFortUIBlueprintFunctionLibrary::SetScrollWidget(UUserWidget* Context, UWidget* ToScroll)
{
}

void UFortUIBlueprintFunctionLibrary::SetWidgetCZonesAutomation(UUserWidget* Context, bool bEnabled)
{
}

void UFortUIBlueprintFunctionLibrary::ShowErrorDialog(UUserWidget* Context, FText DisplayMessage, const FString& ErrorCode, EFortErrorSeverity ErrorSeverity)
{
}

void UFortUIBlueprintFunctionLibrary::SortActorArray(const TArray<AActor*>& InActors, TArray<AActor*>& OutSortedActors)
{
}

FString UFortUIBlueprintFunctionLibrary::ToOrdinal(int32 Number)
{
	return FString();
}

void UFortUIBlueprintFunctionLibrary::TryPopActivatablePanel(UUserWidget* Context, UCommonActivatablePanelLegacy* Panel)
{
}

void UFortUIBlueprintFunctionLibrary::TryPushWidgetAsActivatablePanel(UUserWidget* Context, UUserWidget* PushWidget, EActivatePanelOption Header, EActivatePanelOption Footer, EActivatePanelOption ChatWidget)
{
}

void UFortUIBlueprintFunctionLibrary::TryPushWidgetAsActivatablePanelForPlayer(APlayerController* OwningPlayer, UUserWidget* PushWidget, EActivatePanelOption Header, EActivatePanelOption Footer, EActivatePanelOption ChatWidget)
{
}

void UFortUIBlueprintFunctionLibrary::TryPushWidgetAsModalPanel(UUserWidget* Context, UUserWidget* PushWidget)
{
}

void UFortUIBlueprintFunctionLibrary::TryPushWidgetAsModalPanelForPlayer(AFortPlayerController* LocalPlayerController, UUserWidget* PushWidget)
{
}

void UFortUIBlueprintFunctionLibrary::UnregisterActiveCinematic(UObject* Context)
{
}
