// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortActivityVideoCycle.generated.h"

class UFortActivatableMovieWidget;
class UFortGameActivity;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortActivityVideoCycleClosed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortActivityVideoCycleEndReached);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortActivityVideoCycleStarted);

UCLASS(meta=(DisableNativeTick))
class UFortActivityVideoCycle : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void PlayVideoBumper();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void PlayVideoIntro();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void PlayVideoOutro();

protected:
	UFUNCTION(BlueprintPure)
	const UFortGameActivity* GetSelectedGameActivity() const;

private:
	UFUNCTION()
	void HandleMovieWidgetMediaClosed();

	UFUNCTION()
	void HandleMovieWidgetMediaEndReached();

	UFUNCTION()
	void HandleMovieWidgetMediaError(const FString& StreamedVideoError);

	UFUNCTION()
	void HandleMovieWidgetMediaOpened(const FString& OpenedURL);

	UFUNCTION()
	void HandleMovieWidgetMediaOpenFailed(const FString& FailedURL);

	UFUNCTION()
	void HandleMovieWidgetMediaPreEndEvent();

	UFUNCTION()
	void HandleMovieWidgetMediaStarted();

	UFUNCTION()
	void HandleVideoCycleClosed();

	UFUNCTION(BlueprintCallable, meta=(AllowPrivateAccess))
	void PlaySelectedActivityMovie();

	UPROPERTY(EditDefaultsOnly, Category="FortActivityVideoCycle")
	TSubclassOf<UFortActivatableMovieWidget> MovieWidgetClass;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortActivityVideoCycle", meta=(AllowPrivateAccess, BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UFortActivatableMovieWidget> ActivityMovieWidget;

	UPROPERTY(EditAnywhere, Category="FortActivityVideoCycle")
	float MovieStartDelay;

	UPROPERTY(EditAnywhere, Category="FortActivityVideoCycle")
	float MovieRestartDelay;

};

