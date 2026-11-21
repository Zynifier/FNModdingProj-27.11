// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "UObject/NoExportTypes.h"
#include "PictureInPicturePartnerSource.h"
#include "UPictureInPictureSubsystem.generated.h"

class UFortMediaCMSEventsComponent;
class UMediaCMSEvent;
class UObject;
class UPictureInPictureClient;
class UPictureInPictureMediaController;
class UPictureInPicturePartnerControls;
class UPictureInPicturePartnerDataAsset;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPictureInPicurePartnerChanged, UPictureInPicturePartnerControls*, NewPartner);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPictureInPicurePartnerUpdateComplete);

UCLASS(BlueprintType)
class UPictureInPicturePartnerControls : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="PictureInPicturePartnerControls")
	bool bRequiresAgeOfConsent;

	UPROPERTY(BlueprintReadWrite, Category="PictureInPicturePartnerControls")
	TObjectPtr<UPictureInPictureClient> ClientObject;

	UPROPERTY(BlueprintReadWrite, Category="PictureInPicturePartnerControls")
	TObjectPtr<UPictureInPictureMediaController> MediaController;

};

UCLASS(BlueprintType, Blueprintable)
class PICTUREINPICTURECORE_API UPictureInPictureSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void EnableFullScreenPiPOption(const bool bEnable);

	UFUNCTION(BlueprintCallable)
	bool GetAutoEnableSetting();

	UFUNCTION(BlueprintCallable)
	UPictureInPictureClient* GetCurrentPartnerClient();

	UFUNCTION(BlueprintCallable)
	UPictureInPictureMediaController* GetCurrentPartnerController();

	UFUNCTION(BlueprintCallable)
	UPictureInPicturePartnerControls* GetCurrentPartnerControls();

	UFUNCTION(BlueprintCallable)
	UPictureInPicturePartnerDataAsset* GetCurrentPartnerItem();

	UFUNCTION(BlueprintCallable)
	void GetLastUsedPartner(FString& OutPartnerName);

	UFUNCTION(BlueprintCallable)
	void GetLastUsedSource(FString& OutPartnerSourceName);

	UFUNCTION(BlueprintCallable)
	UPictureInPictureClient* GetPartnerClient(const FString& PartnerName);

	UFUNCTION(BlueprintCallable)
	UPictureInPictureMediaController* GetPartnerController(const FString& PartnerName);

	UFUNCTION(BlueprintCallable)
	UPictureInPicturePartnerControls* GetPartnerControls(const FString& PartnerName);

	UFUNCTION(BlueprintCallable)
	UPictureInPicturePartnerDataAsset* GetPartnerItem(const FString& PartnerName);

	UFUNCTION(BlueprintCallable)
	const TArray<UPictureInPicturePartnerDataAsset*>& GetPartnerItemList();

	UFUNCTION(BlueprintCallable)
	bool IsPartnerListUpdated();

	UFUNCTION()
	void ResumeCurrentMediaController();

	UFUNCTION(BlueprintCallable)
	void ShutdownAllPartners();

	UFUNCTION(BlueprintCallable)
	void StoreAutoEnableSetting(bool InUserEnabled);

	UFUNCTION(BlueprintCallable)
	void StoreLastUsedPartner(const FString& InPartnerName);

	UFUNCTION(BlueprintCallable)
	void StoreLastUsedSource(const FString& InPartnerSourceName);

	UFUNCTION()
	void SuspendCurrentMediaController();

	UFUNCTION()
	void ToggleFullScreenPiP();

	UFUNCTION(BlueprintCallable)
	void UpdatePartnerItemList(UObject* InWorldContext, bool bForce = false);

	UPROPERTY(BlueprintReadWrite, Category="PictureInPictureSubsystem")
	TArray<TObjectPtr<UPictureInPicturePartnerDataAsset>> AvailableClientsList;

	UPROPERTY(BlueprintAssignable)
	FPictureInPicurePartnerUpdateComplete OnPartnerUpdateComplete;

	UPROPERTY(BlueprintAssignable)
	FPictureInPicurePartnerChanged OnPartnerChanged;

private:
	UFUNCTION()
	void HandleFNEventsSetCurrentMediaControllerEnabled(bool InEnabled);

	UFUNCTION()
	void HandleMediaSourceRequest();

	UFUNCTION()
	void OnCMSEventInvalid(const UMediaCMSEvent* InvalidEvent);

	UFUNCTION()
	void OnCMSEventValid(const UMediaCMSEvent* ValidEvent);

	UFUNCTION()
	void OnCurrentPartnerSourceSelected(const FPiPPartnerSource& SelectedSource);

	UPROPERTY()
	bool bPartnerListUpdated;

	UPROPERTY()
	bool bIsSuspended;

	UPROPERTY()
	bool bCMSInitialized;

	UPROPERTY(Transient)
	FString CurrentPlatform;

	UPROPERTY()
	TMap<FString, TObjectPtr<UPictureInPicturePartnerControls>> SupportedPartnerControls;

	UPROPERTY()
	FString CurrentPartnerName;

	UPROPERTY(Transient)
	FString CurrentContinent;

	UPROPERTY(Transient)
	FString CurrentCountry;

	UPROPERTY(Transient)
	TArray<FString> CurrentSubdivisions;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMediaCMSEventsComponent> CMSEventsComponent;

};

