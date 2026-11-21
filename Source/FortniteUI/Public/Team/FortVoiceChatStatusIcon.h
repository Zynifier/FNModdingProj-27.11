// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"
#include "FortVoiceChatStatusIcon.generated.h"

class UFortSocialUser;
class UMaterialInterface;

UCLASS()
class FORTNITEUI_API UFortVoiceChatStatusIcon : public UWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetImageColorAndOpacity(const FSlateColor& InColorAndOpacity);

	UFUNCTION(BlueprintCallable)
	void SetPlayerNetIdFromFortUser(UFortSocialUser* InSocialUser);

private:
	UPROPERTY(EditAnywhere, Category="FortVoiceChatStatusIcon")
	FVector2D DesiredSize;

	UPROPERTY(EditAnywhere, Category="FortVoiceChatStatusIcon")
	FSlateColor ImageColorAndOpacity;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInterface> VoiceChatStatusMaterial;

	UPROPERTY(Transient)
	FSlateBrush StatusBrush;

};

UCLASS()
class FORTNITEUI_API UFortVoiceChatStatusIconProxyAnim : public UFortVoiceChatStatusIcon
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Voice")
	float TalkingRampUpSeconds;

	UPROPERTY(EditAnywhere, Category="Voice")
	float TalkingRampDownSeconds;

	UPROPERTY(EditAnywhere, Category="Voice")
	float TalkingUpdatesPerSecond;

};

