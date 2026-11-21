// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortActorIndicatorWidget.h"
#include "FortConversationMarkerInterface.h"
#include "FortConversationMarker.generated.h"

class AActor;
class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UFortConversationMessageWidget;
class UFortKeybindWidget;
class UFortNonPlayerConversationParticipantComponent;
class UImage;
class UTexture2D;
class UWidget;
enum class EInteractionRange : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortConversationMarker : public UFortActorIndicatorWidget, public IFortConversationMarkerInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCanInteract(bool bCanInteract);

	UFUNCTION(BlueprintImplementableEvent, Category="Conversation")
	void OnConversationActorProximityChanged(EInteractionRange TargetInteractionRange, UFortNonPlayerConversationParticipantComponent* ConversationComponent);

	UFUNCTION(BlueprintImplementableEvent, Category="Conversation")
	void OnInteractionRangeChanged(EInteractionRange TargetInteractionRange);

	UFUNCTION(BlueprintImplementableEvent, Category="Conversation")
	void OnMessageShownOverActor(AActor* OverActor);

	UFUNCTION(BlueprintImplementableEvent, Category="Conversation")
	void OnSetIndicatedActor(AActor* NewIndicatorActor);

private:
	UPROPERTY(Transient)
	FVector InitialOffset;

	UPROPERTY(Transient)
	FVector ManualOffset;

	UPROPERTY(EditAnywhere, Category="Conversation")
	float MessageBubbleDuration;

	UPROPERTY(EditAnywhere, Category="Conversation End")
	float LastTextBubbleDuration;

	UPROPERTY(EditAnywhere, Category="Conversation")
	bool bSetCustomInteractionWidgetOnlyWhenNeeded;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_States;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConversationMarker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_PreviewState;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConversationMarker", meta=(AllowPrivateAccess, BindWidget, DisplayName="Conversation Message", EditInline="true"))
	TObjectPtr<UFortConversationMessageWidget> ConversationMessage_Main;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConversationMarker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ParticipantName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConversationMarker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Keybind_Nameplate;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConversationMarker", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> NPCIcon;

	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> CustomDialogMarkerIndicatorIcon;

	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> DefaultDialogMarkerIndicatorIcon;

};

