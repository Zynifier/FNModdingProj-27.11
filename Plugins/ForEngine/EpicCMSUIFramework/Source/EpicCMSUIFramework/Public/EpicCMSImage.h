// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonLazyImage.h"
#include "Styling/SlateBrush.h"
#include "EpicCMSImage.generated.h"

class UTexture2D;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FonLoadingCompleted);

UCLASS(BlueprintType, Blueprintable)
class EPICCMSUIFRAMEWORK_API UEpicCMSImage : public UCommonLazyImage
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="URL")
	void SetMediaURL(const FString& MediaUrl);

	UPROPERTY(BlueprintAssignable, Category="LazyImage")
	FonLoadingCompleted OnImageLoadingComplete;

private:
	UPROPERTY(EditAnywhere, Category="Appearance")
	bool bMatchImageSize;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush LoadingFailFallback;

	UPROPERTY(Transient)
	TObjectPtr<UTexture2D> ExternalMedia;

	UPROPERTY(Transient)
	bool bDownloadingExternalMedia;

};

