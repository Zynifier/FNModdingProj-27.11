// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UPictureInPictureClient.generated.h"

class UEpicCMSImage;
class UObject;
class UTexture2DDynamic;

UENUM(BlueprintType)
enum PictureInPictureAuthState
{
	UNKNOWN = 0,
	NOT_AUTHORIZED = 1,
	AUTHORIZED = 2,
};

UENUM(BlueprintType)
enum PictureInPictureAuthType
{
	AUTH_NONE = 0,
	AUTH_USER_PASS = 1,
	AUTH_QR_CODE = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPictureInPictureClientError, FString, ErrorName, FString, ErrorMessage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPictureInPictureClientLoginSuccess);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPictureInPictureClientLogoutSuccess);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPictureInPictureClientQRCodeAvailable, UTexture2DDynamic*, QRCodeTexture);

UCLASS(Abstract, BlueprintType, Blueprintable)
class PICTUREINPICTURECORE_API UPictureInPictureClient : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void BeginLogin(UObject* InWorldContext);

	UFUNCTION(BlueprintCallable)
	virtual void CheckLogin(UObject* InWorldContext);

	UFUNCTION(BlueprintCallable)
	virtual void EndLogin(UObject* InWorldContext);

	UFUNCTION(BlueprintCallable)
	UEpicCMSImage* GetAvatarImage();

	UFUNCTION(BlueprintCallable)
	const PictureInPictureAuthState GetLoginState();

	UFUNCTION(BlueprintCallable)
	UTexture2DDynamic* GetQRCodeTexture();

	UFUNCTION(BlueprintCallable)
	virtual bool IsLoggedIn();

	UFUNCTION(BlueprintCallable)
	virtual void Logout();

	UPROPERTY(BlueprintAssignable)
	FPictureInPictureClientLoginSuccess LoginSuccessEvent;

	UPROPERTY(BlueprintAssignable)
	FPictureInPictureClientLogoutSuccess LogoutSuccessEvent;

	UPROPERTY(BlueprintAssignable)
	FPictureInPictureClientQRCodeAvailable QRCodeReceivedEvent;

	UPROPERTY(BlueprintAssignable)
	FPictureInPictureClientError ErrorDelegate;

protected:
	UPROPERTY(BlueprintReadOnly, Category="PictureInPictureClient")
	FString UserName;

	UPROPERTY(BlueprintReadWrite, Export, Category="PictureInPictureClient", meta=(EditInline="true"))
	TObjectPtr<UEpicCMSImage> UserAvatarImage;

	UPROPERTY(BlueprintReadOnly, Category="PictureInPictureClient")
	TObjectPtr<UTexture2DDynamic> CurrentQRCodeTexture;

};

